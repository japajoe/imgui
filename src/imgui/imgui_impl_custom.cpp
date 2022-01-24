#include "imgui.h"
#include "imgui_impl_custom.h"
#include <cstdint>
#include <iostream>

static uint64_t     g_Time = 0;
static bool         g_MousePressed[3] = { false, false, false };
static int          g_MouseCursors[ImGuiMouseCursor_COUNT] = {};
static const char*  g_ClipboardTextData = NULL;
static bool         g_MouseCanUseGlobalState = true;

static SetClipboardTextPtr setClipboardText = nullptr;
static GetClipboardTextPtr getClipboardText = nullptr;
static ShowMouseCursorPtr showMouseCursor = nullptr;
static SetMouseCursorPtr setMouseCursor = nullptr;
static WarpMousePtr warpMouse = nullptr;
static GetMousePositionPtr getMousePosition = nullptr;
static GetWindowPositionPtr getWindowPosition = nullptr;
static CreateCursorPtr createCursor = nullptr;
static GetMouseButtonPtr getMouseButton = nullptr;
static ImGuiImplKeybindings keybinds;
static ImGuiImplCursorType cursorType;
static ImGuiImplMouseButton mouseButton;

static const char* ImGui_ImplCustom_GetClipboardText(void*)
{
    g_ClipboardTextData = getClipboardText();
    return g_ClipboardTextData;
}

static void ImGui_ImplCustom_SetClipboardText(void*, const char* text)
{
    setClipboardText(text);
}

bool ImGui_ImplCustom_ProcessEvent(const ImGuiImplWindowEventType event, const ImGuiImplKeyboardState keyboardState, const ImGuiImplMouseState mouseState, const char* inputText)
{
    ImGuiIO& io = ImGui::GetIO();

    switch (event)
    {
        case ImGuiImplWindowEventType::MOUSEWHEEL:
        {
            if (mouseState.wheelX > 0) 
                io.MouseWheelH += 1;
            if (mouseState.wheelX < 0) 
                io.MouseWheelH -= 1;
            if (mouseState.wheelY > 0) 
                io.MouseWheel += 1;
            if (mouseState.wheelY < 0) 
                io.MouseWheel -= 1;
            return true;
        }
        case ImGuiImplWindowEventType::MOUSEBUTTONDOWN:
        {
            if (mouseState.buttonLeft == 1) 
                g_MousePressed[0] = true;
            if (mouseState.buttonRight == 1) 
                g_MousePressed[1] = true;
            if (mouseState.buttonMiddle == 1) 
                g_MousePressed[2] = true;
            return true;
        }
        case ImGuiImplWindowEventType::TEXTINPUT:
        {
            io.AddInputCharactersUTF8(inputText);
            return true;
        }
        case ImGuiImplWindowEventType::KEYDOWN:
        case ImGuiImplWindowEventType::KEYUP:
        {
            int key = keyboardState.scancode;
            IM_ASSERT(key >= 0 && key < IM_ARRAYSIZE(io.KeysDown));
            io.KeysDown[key] = (event == ImGuiImplWindowEventType::KEYDOWN);
            io.KeyShift = keyboardState.shiftIsDown;
            io.KeyCtrl = keyboardState.controlisDown;
            io.KeyAlt = keyboardState.altIsDown;
            io.KeySuper = keyboardState.superIsDown;
            return true;
        }
        default:
            return false;
    }
}

static bool ImGui_ImplCustom_Init()
{
    // Setup backend capabilities flags
    ImGuiIO& io = ImGui::GetIO();
    io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;       // We can honor GetMouseCursor() values (optional)
    io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;        // We can honor io.WantSetMousePos requests (optional, rarely used)
    io.BackendPlatformName = "imgui_impl_custom";

    // Keyboard mapping. ImGui will use those indices to peek into the io.KeysDown[] array.
    io.KeyMap[ImGuiKey_Tab] = keybinds.Tab;
    io.KeyMap[ImGuiKey_LeftArrow] = keybinds.LeftArrow;
    io.KeyMap[ImGuiKey_RightArrow] = keybinds.RightArrow;
    io.KeyMap[ImGuiKey_UpArrow] = keybinds.UpArrow;
    io.KeyMap[ImGuiKey_DownArrow] = keybinds.DownArrow;
    io.KeyMap[ImGuiKey_PageUp] = keybinds.PageUp;
    io.KeyMap[ImGuiKey_PageDown] = keybinds.PageDown;
    io.KeyMap[ImGuiKey_Home] = keybinds.Home;
    io.KeyMap[ImGuiKey_End] = keybinds.End;
    io.KeyMap[ImGuiKey_Insert] = keybinds.Insert;
    io.KeyMap[ImGuiKey_Delete] = keybinds.Delete;
    io.KeyMap[ImGuiKey_Backspace] = keybinds.Backspace;
    io.KeyMap[ImGuiKey_Space] = keybinds.Space;
    io.KeyMap[ImGuiKey_Enter] = keybinds.Enter;
    io.KeyMap[ImGuiKey_Escape] = keybinds.Escape;
    io.KeyMap[ImGuiKey_KeyPadEnter] = keybinds.KeyPadEnter;
    io.KeyMap[ImGuiKey_A] = keybinds.A;
    io.KeyMap[ImGuiKey_C] = keybinds.C;
    io.KeyMap[ImGuiKey_V] = keybinds.V;
    io.KeyMap[ImGuiKey_X] = keybinds.X;
    io.KeyMap[ImGuiKey_Y] = keybinds.Y;
    io.KeyMap[ImGuiKey_Z] = keybinds.Z;

    io.SetClipboardTextFn = ImGui_ImplCustom_SetClipboardText;
    io.GetClipboardTextFn = ImGui_ImplCustom_GetClipboardText;
    io.ClipboardUserData = NULL;

    // Load mouse cursors
    g_MouseCursors[ImGuiMouseCursor_Arrow] = createCursor(cursorType.Arrow);
    g_MouseCursors[ImGuiMouseCursor_TextInput] = createCursor(cursorType.TextInput);
    g_MouseCursors[ImGuiMouseCursor_ResizeAll] = createCursor(cursorType.ResizeAll);
    g_MouseCursors[ImGuiMouseCursor_ResizeNS] = createCursor(cursorType.ResizeNS);
    g_MouseCursors[ImGuiMouseCursor_ResizeEW] = createCursor(cursorType.ResizeEW);
    g_MouseCursors[ImGuiMouseCursor_ResizeNESW] = createCursor(cursorType.ResizeNESW);
    g_MouseCursors[ImGuiMouseCursor_ResizeNWSE] = createCursor(cursorType.ResizeNWSE);
    g_MouseCursors[ImGuiMouseCursor_Hand] = createCursor(cursorType.Hand);
    g_MouseCursors[ImGuiMouseCursor_NotAllowed] = createCursor(cursorType.NotAllowed);

    // Check and store if we are on Wayland
    g_MouseCanUseGlobalState = false;

    return true;
}

bool ImGui_ImplCustom_InitForOpenGL(ImGuiImplCallbackTypes callbacks, ImGuiImplKeybindings keybindings, ImGuiImplCursorType cursorTypes, ImGuiImplMouseButton mouseButtons)
{
    setClipboardText = callbacks.setClipboardText;
    getClipboardText = callbacks.getClipboardText;
    showMouseCursor = callbacks.showMouseCursor;
    setMouseCursor = callbacks.setMouseCursor;
    warpMouse = callbacks.warpMouse;
    getMousePosition = callbacks.getMousePosition;
    getWindowPosition = callbacks.getWindowPosition;
    createCursor = callbacks.createCursor;
    getMouseButton = callbacks.getMouseButton;

    keybinds = keybindings;
    cursorType = cursorTypes;
    mouseButton = mouseButtons;

    return ImGui_ImplCustom_Init();
}

void ImGui_ImplCustom_Shutdown()
{
    // Destroy last known clipboard data
    g_ClipboardTextData = NULL;
}

static void ImGui_ImplCustom_UpdateMousePosAndButtons()
{
    ImGuiIO& io = ImGui::GetIO();

    // Set OS mouse position if requested (rarely used, only when ImGuiConfigFlags_NavEnableSetMousePos is enabled by user)
    if (io.WantSetMousePos)
        warpMouse((int)io.MousePos.x, (int)io.MousePos.y);
    else
        io.MousePos = ImVec2(-FLT_MAX, -FLT_MAX);

    io.MouseDown[0] = g_MousePressed[0] || getMouseButton(mouseButton.Left) != 0;  // If a mouse press event came, always pass it as "mouse held this frame", so we don't miss click-release events that are shorter than 1 frame.
    io.MouseDown[1] = g_MousePressed[1] || getMouseButton(mouseButton.Right) != 0;
    io.MouseDown[2] = g_MousePressed[2] || getMouseButton(mouseButton.Middle) != 0;

    g_MousePressed[0] = g_MousePressed[1] = g_MousePressed[2] = false;

    int mx;
    int my;
    getMousePosition(&mx, &my);
    io.MousePos = ImVec2((float)mx, (float)my);
}

static void ImGui_ImplCustom_UpdateMouseCursor()
{
    ImGuiIO& io = ImGui::GetIO();
    if (io.ConfigFlags & ImGuiConfigFlags_NoMouseCursorChange)
        return;

    ImGuiMouseCursor imgui_cursor = ImGui::GetMouseCursor();
    if (io.MouseDrawCursor || imgui_cursor == ImGuiMouseCursor_None)
    {
        // Hide OS mouse cursor if imgui is drawing it or if it wants no cursor
        showMouseCursor(false);
    }
    else
    {
        // Show OS mouse cursor
        setMouseCursor(0);
        showMouseCursor(true);
    }
}

void ImGui_ImplCustom_NewFrame(const ImGuiImplFrameSettings frameSettings)
{
    ImGuiIO& io = ImGui::GetIO();
    IM_ASSERT(io.Fonts->IsBuilt() && "Font atlas not built! It is generally built by the renderer backend. Missing call to renderer _NewFrame() function? e.g. ImGui_ImplOpenGL3_NewFrame().");

    // Setup display size (every frame to accommodate for window resizing)
    int w, h;
    int display_w, display_h;
    
    w = frameSettings.windowWidth;
    h = frameSettings.windowHeight;

    if (frameSettings.isMinimized)
        w = h = 0;
    
    display_h = frameSettings.drawableHeight;
    display_w = frameSettings.drawableWidth;
    io.DisplaySize = ImVec2((float)w, (float)h);
    
    if (w > 0 && h > 0)
        io.DisplayFramebufferScale = ImVec2((float)display_w / w, (float)display_h / h);

    io.DeltaTime = frameSettings.deltaTime;

    ImGui_ImplCustom_UpdateMousePosAndButtons();
    ImGui_ImplCustom_UpdateMouseCursor();
}