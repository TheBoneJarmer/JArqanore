package be.labruyere.arqanore.utils;

import be.labruyere.arqanore.enums.*;

public class EnumUtils {
    public static int convertMouseButton(MouseButtons value) {
        if (value == MouseButtons.BUTTON1) return 0;
        if (value == MouseButtons.BUTTON2) return 1;
        if (value == MouseButtons.BUTTON3) return 2;
        if (value == MouseButtons.BUTTON4) return 3;
        if (value == MouseButtons.BUTTON5) return 4;
        if (value == MouseButtons.BUTTON6) return 5;
        if (value == MouseButtons.BUTTON7) return 6;
        if (value == MouseButtons.BUTTON8) return 7;

        if (value == MouseButtons.LEFT) return 0;
        if (value == MouseButtons.RIGHT) return 1;
        if (value == MouseButtons.MIDDLE) return 2;

        return -1;
    }

    public static Keys convertKey(int value) {
        if (value == 32) return Keys.SPACE;
        if (value == 39) return Keys.APOSTROPHE;
        if (value == 44) return Keys.COMMA;
        if (value == 45) return Keys.MINUS;
        if (value == 46) return Keys.PERIOD;
        if (value == 47) return Keys.SLASH;
        if (value == 48) return Keys.A0;
        if (value == 49) return Keys.A1;
        if (value == 50) return Keys.A2;
        if (value == 51) return Keys.A3;
        if (value == 52) return Keys.A4;
        if (value == 53) return Keys.A5;
        if (value == 54) return Keys.A6;
        if (value == 55) return Keys.A7;
        if (value == 56) return Keys.A8;
        if (value == 57) return Keys.A9;
        if (value == 59) return Keys.SEMICOLON;
        if (value == 61) return Keys.EQUAL;
        if (value == 65) return Keys.A;
        if (value == 66) return Keys.B;
        if (value == 67) return Keys.C;
        if (value == 68) return Keys.D;
        if (value == 69) return Keys.E;
        if (value == 70) return Keys.F;
        if (value == 71) return Keys.G;
        if (value == 72) return Keys.H;
        if (value == 73) return Keys.I;
        if (value == 74) return Keys.J;
        if (value == 75) return Keys.K;
        if (value == 76) return Keys.L;
        if (value == 77) return Keys.M;
        if (value == 78) return Keys.N;
        if (value == 79) return Keys.O;
        if (value == 80) return Keys.P;
        if (value == 81) return Keys.Q;
        if (value == 82) return Keys.R;
        if (value == 83) return Keys.S;
        if (value == 84) return Keys.T;
        if (value == 85) return Keys.U;
        if (value == 86) return Keys.V;
        if (value == 87) return Keys.W;
        if (value == 88) return Keys.X;
        if (value == 89) return Keys.Y;
        if (value == 90) return Keys.Z;
        if (value == 91) return Keys.LEFTBRACKET;
        if (value == 92) return Keys.BACKSLASH;
        if (value == 93) return Keys.RIGHTBRACKET;
        if (value == 96) return Keys.GRAVE;
        if (value == 161) return Keys.WORLD1;
        if (value == 162) return Keys.WORLD2;
        if (value == 256) return Keys.ESCAPE;
        if (value == 257) return Keys.ENTER;
        if (value == 258) return Keys.TAB;
        if (value == 259) return Keys.BACKSPACE;
        if (value == 261) return Keys.DELETE;
        if (value == 262) return Keys.RIGHT;
        if (value == 263) return Keys.LEFT;
        if (value == 264) return Keys.DOWN;
        if (value == 265) return Keys.UP;
        if (value == 266) return Keys.PAGEUP;
        if (value == 267) return Keys.PAGEDOWN;
        if (value == 268) return Keys.HOME;
        if (value == 269) return Keys.END;
        if (value == 280) return Keys.CAPSLOCK;
        if (value == 281) return Keys.SCROLLLOCK;
        if (value == 282) return Keys.NUMLOCK;
        if (value == 283) return Keys.PRTSCR;
        if (value == 284) return Keys.PAUSE;
        if (value == 290) return Keys.F1;
        if (value == 291) return Keys.F2;
        if (value == 292) return Keys.F3;
        if (value == 293) return Keys.F4;
        if (value == 294) return Keys.F5;
        if (value == 295) return Keys.F6;
        if (value == 296) return Keys.F7;
        if (value == 297) return Keys.F8;
        if (value == 298) return Keys.F9;
        if (value == 299) return Keys.F10;
        if (value == 300) return Keys.F11;
        if (value == 301) return Keys.F12;
        if (value == 320) return Keys.KEYPAD0;
        if (value == 321) return Keys.KEYPAD1;
        if (value == 322) return Keys.KEYPAD2;
        if (value == 323) return Keys.KEYPAD3;
        if (value == 324) return Keys.KEYPAD4;
        if (value == 325) return Keys.KEYPAD5;
        if (value == 326) return Keys.KEYPAD6;
        if (value == 327) return Keys.KEYPAD7;
        if (value == 328) return Keys.KEYPAD8;
        if (value == 329) return Keys.KEYPAD9;
        if (value == 330) return Keys.KEYPADDECIMAL;
        if (value == 331) return Keys.KEYPADDIVIDE;
        if (value == 332) return Keys.KEYPADMULTIPLY;
        if (value == 333) return Keys.KEYPADSUBTRACT;
        if (value == 334) return Keys.KEYPADADD;
        if (value == 335) return Keys.KEYPADENTER;
        if (value == 336) return Keys.KEYPADEQUAL;
        if (value == 340) return Keys.LEFTSHIFT;
        if (value == 341) return Keys.LEFTCTRL;
        if (value == 342) return Keys.LEFTALT;
        if (value == 343) return Keys.LEFTSUPER;
        if (value == 344) return Keys.RIGHTSHIFT;
        if (value == 345) return Keys.RIGHTCTRL;
        if (value == 346) return Keys.RIGHTALT;
        if (value == 347) return Keys.RIGHTSUPER;
        if (value == 348) return Keys.MENU;

        return null;
    }

    public static int convertKey(Keys value) {
        if (value == Keys.SPACE) return 32;
        if (value == Keys.APOSTROPHE) return 39;
        if (value == Keys.COMMA) return 44;
        if (value == Keys.MINUS) return 45;
        if (value == Keys.PERIOD) return 46;
        if (value == Keys.SLASH) return 47;
        if (value == Keys.A0) return 48;
        if (value == Keys.A1) return 49;
        if (value == Keys.A2) return 50;
        if (value == Keys.A3) return 51;
        if (value == Keys.A4) return 52;
        if (value == Keys.A5) return 53;
        if (value == Keys.A6) return 54;
        if (value == Keys.A7) return 55;
        if (value == Keys.A8) return 56;
        if (value == Keys.A9) return 57;
        if (value == Keys.SEMICOLON) return 59;
        if (value == Keys.EQUAL) return 61;
        if (value == Keys.A) return 65;
        if (value == Keys.B) return 66;
        if (value == Keys.C) return 67;
        if (value == Keys.D) return 68;
        if (value == Keys.E) return 69;
        if (value == Keys.F) return 70;
        if (value == Keys.G) return 71;
        if (value == Keys.H) return 72;
        if (value == Keys.I) return 73;
        if (value == Keys.J) return 74;
        if (value == Keys.K) return 75;
        if (value == Keys.L) return 76;
        if (value == Keys.M) return 77;
        if (value == Keys.N) return 78;
        if (value == Keys.O) return 79;
        if (value == Keys.P) return 80;
        if (value == Keys.Q) return 81;
        if (value == Keys.R) return 82;
        if (value == Keys.S) return 83;
        if (value == Keys.T) return 84;
        if (value == Keys.U) return 85;
        if (value == Keys.V) return 86;
        if (value == Keys.W) return 87;
        if (value == Keys.X) return 88;
        if (value == Keys.Y) return 89;
        if (value == Keys.Z) return 90;
        if (value == Keys.LEFTBRACKET) return 91;
        if (value == Keys.BACKSLASH) return 92;
        if (value == Keys.RIGHTBRACKET) return 93;
        if (value == Keys.GRAVE) return 96;
        if (value == Keys.WORLD1) return 161;
        if (value == Keys.WORLD2) return 162;
        if (value == Keys.ESCAPE) return 256;
        if (value == Keys.ENTER) return 257;
        if (value == Keys.TAB) return 258;
        if (value == Keys.BACKSPACE) return 259;
        if (value == Keys.DELETE) return 261;
        if (value == Keys.RIGHT) return 262;
        if (value == Keys.LEFT) return 263;
        if (value == Keys.DOWN) return 264;
        if (value == Keys.UP) return 265;
        if (value == Keys.PAGEUP) return 266;
        if (value == Keys.PAGEDOWN) return 267;
        if (value == Keys.HOME) return 268;
        if (value == Keys.END) return 269;
        if (value == Keys.CAPSLOCK) return 280;
        if (value == Keys.SCROLLLOCK) return 281;
        if (value == Keys.NUMLOCK) return 282;
        if (value == Keys.PRTSCR) return 283;
        if (value == Keys.PAUSE) return 284;
        if (value == Keys.F1) return 290;
        if (value == Keys.F2) return 291;
        if (value == Keys.F3) return 292;
        if (value == Keys.F4) return 293;
        if (value == Keys.F5) return 294;
        if (value == Keys.F6) return 295;
        if (value == Keys.F7) return 296;
        if (value == Keys.F8) return 297;
        if (value == Keys.F9) return 298;
        if (value == Keys.F10) return 299;
        if (value == Keys.F11) return 300;
        if (value == Keys.F12) return 301;
        if (value == Keys.KEYPAD0) return 320;
        if (value == Keys.KEYPAD1) return 321;
        if (value == Keys.KEYPAD2) return 322;
        if (value == Keys.KEYPAD3) return 323;
        if (value == Keys.KEYPAD4) return 324;
        if (value == Keys.KEYPAD5) return 325;
        if (value == Keys.KEYPAD6) return 326;
        if (value == Keys.KEYPAD7) return 327;
        if (value == Keys.KEYPAD8) return 328;
        if (value == Keys.KEYPAD9) return 329;
        if (value == Keys.KEYPADDECIMAL) return 330;
        if (value == Keys.KEYPADDIVIDE) return 331;
        if (value == Keys.KEYPADMULTIPLY) return 332;
        if (value == Keys.KEYPADSUBTRACT) return 333;
        if (value == Keys.KEYPADADD) return 334;
        if (value == Keys.KEYPADENTER) return 335;
        if (value == Keys.KEYPADEQUAL) return 336;
        if (value == Keys.LEFTSHIFT) return 340;
        if (value == Keys.LEFTCTRL) return 341;
        if (value == Keys.LEFTALT) return 342;
        if (value == Keys.LEFTSUPER) return 343;
        if (value == Keys.RIGHTSHIFT) return 344;
        if (value == Keys.RIGHTCTRL) return 345;
        if (value == Keys.RIGHTALT) return 346;
        if (value == Keys.RIGHTSUPER) return 347;
        if (value == Keys.MENU) return 348;

        return -1;
    }

    public static int convertShaderTarget(ShaderTarget value) {
        if (value == ShaderTarget.FONT) return 0;
        if (value == ShaderTarget.POLYGON) return 1;
        if (value == ShaderTarget.SPRITE) return 2;
        if (value == ShaderTarget.MODEL) return 3;

        return -1;
    }

    public static int convertShaderSourceType(ShaderSourceType value) {
        if (value == ShaderSourceType.RAW) return 0;
        if (value == ShaderSourceType.FILE) return 1;

        return -1;
    }

    public static int convertLightType(LightType value) {
        if (value == LightType.DIRECTIONAL) return 0;
        if (value == LightType.POINT) return 1;

        return -1;
    }

    public static LightType convertLightType(int value) {
        if (value == 0) return LightType.DIRECTIONAL;
        if (value == 1) return LightType.POINT;

        return null;
    }

    public static int convertRigidBodyType(RigidBodyType value) {
        if (value == RigidBodyType.DYNAMIC) return 0;
        if (value == RigidBodyType.STATIC) return 1;

        return -1;
    }
}
