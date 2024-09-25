$JAVAC="$env:JAVA_HOME/bin/javac"
$JAR="$env:JAVA_HOME/bin/jar"
$JAVADOC="$env:JAVA_HOME/bin/javadoc"

$ErrorActionPreference = "Stop"

# HELPER METHODS
function GetFullPath([string] $path) {
    return [System.IO.Path]::GetFullPath("$pwd" + "/" + $path)
}

function GetFilesFromFolder([string] $path, [string] $pattern) {
    return [System.IO.Directory]::GetFiles($path, $pattern, [System.IO.SearchOption]::AllDirectories)
}

function GetJavaSourceString() {
    $result = ""
	
	if ($IsWindows) {
		$files = GetFilesFromFolder "$pwd\src\java" "*.java"
    
		foreach ($file in $files) {
			$file = $file.replace("$pwd\src\java\", "")
			$result += "$file "
		}
	}
	
	if ($IsLinux) {
		$files = GetFilesFromFolder "$pwd/src/java" "*.java"
    
		foreach ($file in $files) {
			$file = $file.replace("$pwd/src/java/", "")
			$result += "$file "
		}
	}
    
    return $result
}

function RemoveFolderIfExists([string] $path) {
    if (Test-Path -Path $path) {
        Remove-Item -Path $path -Recurse -Force > $null
    }
}

function CreateFolder([string] $name) {
    New-Item -Path . -Name $name -ItemType "directory" > $null
}

# BUILD METHODS
function InitBuild() {
    RemoveFolderIfExists "out"
    RemoveFolderIfExists "src/cpp/build"
    
    CreateFolder "out"
    CreateFolder "src/cpp/build"
}

function InitCmake() {
    $cwd = GetFullPath "."

    try {
		Write-Host "Generating cmake files"
        Set-Location "$cwd/src/cpp/build"
        
        if ($IsWindows) {
            Invoke-Expression 'cmake -S .. -G "MinGW Makefiles" > $null'
        }
        
        if ($IsLinux) {
            Invoke-Expression 'cmake -S .. -G "Unix Makefiles" > $null'
        }
        
        Set-Location $cwd
    } catch {
        Write-Host $_
        Exit 1
    }
}

function BuildNative() {
    $cwd = GetFullPath "."
       
    try {
		Write-Host "Building native library"
        Set-Location "$cwd/src/cpp/build"
        Invoke-Expression 'cmake --build . > $null'
        
        if ($IsWindows) {
            Copy-Item -Path *.dll -Destination "$cwd/out" > $null
        }
        
        if ($IsLinux) {
            Copy-Item -Path *.so -Destination "$cwd/out" > $null
        }
        
        Set-Location $cwd
    } catch {
        Write-Host $_
        Exit 1
    }
}

function BuildLibrary() {
    $cwd = GetFullPath "."
    $src = GetJavaSourceString
	               
    try {
		Write-Host "Building java library"
        Set-Location "$cwd/src/java"
        Invoke-Expression "$JAVAC -d $cwd/out -g $src > '$null'"
        Set-Location $cwd
    } catch {
        Write-Host $_
        Exit 1
    }
}

function BuildDocs() {
    $cwd = GetFullPath "."
    $src = GetJavaSourceString
                
    try {
		Write-Host "Building java docs"
        Set-Location "$cwd/src/java"
        Invoke-Expression "$JAVADOC -d $cwd/out/doc $src 2> '$null'"
        Set-Location $cwd
    } catch {
        Write-Host $_
        Exit 1
    }
}

function BuildJar() {
    $cwd = GetFullPath "."
        
    if (Test-Path "$cwd/lib") {
		Write-Host "Copying dynamic libraries"
		
        if ($IsWindows) {
            Copy-Item -Path "lib/*.dll" -Destination $cwd/out > $null
        }
        
        if ($IsLinux) {        
           Copy-Item -Path "lib/*.so" -Destination $cwd/out > $null
        }
    }
    
    try {
		Write-Host "Building jar"
        Set-Location $cwd/out
        Invoke-Expression "$JAR -cf jarqanore.jar ./be/"
        Set-Location $cwd
    } catch {
        Write-Host $_
        Exit 1
    }
}

function Cleanup() {
    $cwd = GetFullPath "."
    
    Write-Host "Cleanup"

    RemoveFolderIfExists "$cwd/out/be"
}

# EXECUTION
InitBuild
InitCmake
BuildNative
BuildLibrary
BuildDocs
BuildJar
Cleanup
