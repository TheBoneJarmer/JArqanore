$JAVAC="$env:JAVA_HOME/bin/javac"

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

# BUILD METHODS
function Generate() {
    $cwd = GetFullPath "."
    $src = GetJavaSourceString
    
    Write-Host "Generating header files"
    
    try {
        Set-Location "$cwd/src/java"
        Invoke-Expression "javac -h ../cpp $src"                
        Set-Location $cwd
    } catch {
        Write-Host $_
        Exit 1
    }
}

function Cleanup() {
    $cwd = GetFullPath "."
    $files = GetFilesFromFolder "$cwd/src/java" "*.class"
    
    Write-Host "Cleanup"
    
    foreach ($file in $files) {
        Remove-Item -Path $file -Force
    }
}

# EXECUTE
Generate
Cleanup
