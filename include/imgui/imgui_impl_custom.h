#ifndef IMGUI_IMPL_CUSTOM_H
#define IMGUI_IMPL_CUSTOM_H

#include "imgui.h"      // IMGUI_IMPL_API

typedef void (*SetClipboardTextPtr)(const char* text);
typedef const char* (*GetClipboardTextPtr)();
typedef void (*ShowMouseCursorPtr)(bool show);
typedef void (*SetMouseCursorPtr)(int index);
typedef void (*WarpMousePtr)(int x, int y);
typedef void (*GetMousePositionPtr)(int* x, int* y);
typedef void (*GetWindowPositionPtr)(int* x, int* y);
typedef int (*CreateCursorPtr)(int type);
typedef int (*GetMouseButtonPtr)(int gdkButton);

struct ImGuiImplCallbackTypes
{
    SetClipboardTextPtr setClipboardText;
    GetClipboardTextPtr getClipboardText;
    ShowMouseCursorPtr showMouseCursor;
    SetMouseCursorPtr setMouseCursor;
    WarpMousePtr warpMouse;
    GetMousePositionPtr getMousePosition;
    GetWindowPositionPtr getWindowPosition;
    CreateCursorPtr createCursor;
    GetMouseButtonPtr getMouseButton;
};

enum class ImGuiImplWindowEventType
{
    MOUSEWHEEL,
    MOUSEBUTTONDOWN,
    MOUSEBUTTONUP,
    TEXTINPUT,
    KEYDOWN,
    KEYUP,
    NONE
};

struct ImGuiImplFrameSettings
{
    int windowWidth;
    int windowHeight;
    int drawableWidth;
    int drawableHeight;
    bool isMinimized;
    float deltaTime;
};

struct ImGuiImplMouseState
{
    int buttonLeft;
    int buttonRight;
    int buttonMiddle;
    int wheelX;
    int wheelY;
};

struct ImGuiImplKeybindings
{
    int Tab;
    int LeftArrow;
    int RightArrow;
    int UpArrow;
    int DownArrow;
    int PageUp;
    int PageDown;
    int Home;
    int End;
    int Insert;
    int Delete;
    int Backspace;
    int Space;
    int Enter;
    int Escape;
    int KeyPadEnter;
    int A;
    int C;
    int V;
    int X;
    int Y;
    int Z;
};

struct ImGuiImplKeyboardState
{
    int scancode;
    int shiftIsDown;
    int controlisDown;
    int altIsDown;
    int superIsDown;
};

struct ImGuiImplCursorType
{
    int Arrow;
    int TextInput;
    int ResizeAll;
    int ResizeNS;
    int ResizeEW;
    int ResizeNESW;
    int ResizeNWSE;
    int Hand;
    int NotAllowed;
};

struct ImGuiImplMouseButton
{
    int Left;
    int Right;
    int Middle;
};

IMGUI_IMPL_API bool     ImGui_ImplCustom_InitForOpenGL(ImGuiImplCallbackTypes callbacks, ImGuiImplKeybindings keybindings, ImGuiImplCursorType cursorTypes, ImGuiImplMouseButton mouseButtons);
IMGUI_IMPL_API void     ImGui_ImplCustom_Shutdown();
IMGUI_IMPL_API void     ImGui_ImplCustom_NewFrame(const ImGuiImplFrameSettings frameSettings);
IMGUI_IMPL_API bool     ImGui_ImplCustom_ProcessEvent(const ImGuiImplWindowEventType event, const ImGuiImplKeyboardState keyboardState, const ImGuiImplMouseState mouseState, const char* inputText);

#endif