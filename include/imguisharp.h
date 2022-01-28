#ifndef IMGUISHARP_H
#define IMGUISHARP_H

#include "imgui/imgui_impl_custom.h"
#include "imgui/imgui_impl_opengl3.h"
#include "ConsoleApp.h"
#include <string>

extern "C"
{
    extern bool ImGui_OpenGL3_Init(const char* glsl_version);
    extern void ImGui_OpenGL3_NewFrame();    
    extern void ImGui_OpenGL3_RenderDrawData();
	extern void ImGui_OpenGL3_Shutdown();	

    extern bool ImGui_CustomBackend_InitForOpenGL(ImGuiImplCallbackTypes callbacks, ImGuiImplKeybindings keybindings, ImGuiImplCursorType cursorTypes, ImGuiImplMouseButton mouseButtons);
    extern void ImGui_CustomBackend_Shutdown();
    extern void ImGui_CustomBackend_NewFrame(const ImGuiImplFrameSettings frameSettings);
    extern bool ImGui_CustomBackend_ProcessEvent(const ImGuiImplWindowEventType evnt, const ImGuiImplKeyboardState keyboardState, const ImGuiImplMouseState mouseState, const char* inputText);

    extern void ImGui_Init();
    extern void ImGui_NewFrame();
    extern void ImGui_Render();
    extern void ImGui_DestroyContext();

    extern bool ImGuiBegin(const char* id, bool* active, ImGuiWindowFlags flags);
    extern void ImGuiEnd();
    extern void ImGuiSetNextWindowPos(float x, float y);
    extern void ImGuiSetNextWindowSize(float x, float y);
    extern void ImGuiSetCursorPos(const ImVec2& pos);
    extern void ImGuiSetCursorPosX(float x);
    extern void ImGuiPushStyleColor(ImGuiCol idx, const ImVec4& col);
    extern void ImGuiPopStyleColor(int count = 1);
    extern bool ImGuiIsAnyItemActive();
    extern bool ImGuiIsAnyItemFocused();
    extern bool ImGuiIsAnyItemHovered();
    extern void ImGuiSetKeyboardFocusHere(int offset);
    extern bool ImGuiCheckbox(const char* text, bool* value);
    extern void ImGuiText(const char* text);
    extern bool ImGuiButton(const char* text, const ImVec2& rect);
    extern bool ImGuiImageButton(int textureId, const ImVec2& size, const ImVec2& uv0, const ImVec2& uv1, int frame_padding, const ImVec4& bg_col, const ImVec4& tint_col);
    extern bool ImGuiSliderFloat(const char* label, float* value, float v_min, float v_max, const char* format, float power);
    extern bool ImGuiInputFloat(const char* label, float* value, float step, float step_fast, const char* format, ImGuiInputTextFlags flags);
    extern bool ImGuiInputFloat2(const char* label, float* value, int decimal_precision, ImGuiInputTextFlags flags);
    extern bool ImGuiInputFloat3(const char* label, float* value, int decimal_precision, ImGuiInputTextFlags flags);
    extern bool ImGuiInputFloat4(const char* label, float* value, int decimal_precision, ImGuiInputTextFlags flags);
    extern bool ImGuiInputDouble(const char* label, double* value, double step, double step_fast, const char* format, ImGuiInputTextFlags flags);
    extern bool ImGuiInputInt(const char* label, int* value, double step, double step_fast, const char* format, ImGuiInputTextFlags flags);
    extern bool ImGuiInputInt2(const char* label, int* value, ImGuiInputTextFlags flags);
    extern bool ImGuiInputInt3(const char* label, int* value, ImGuiInputTextFlags flags);
    extern bool ImGuiInputInt4(const char* label, int* value, ImGuiInputTextFlags flags);
    extern bool ImGuiColorEdit3(const char* label, float* color, ImGuiColorEditFlags flags);
    extern bool ImGuiColorEdit4(const char* label, float* color, ImGuiColorEditFlags flags);
    extern void ImGuiImage(int textureId, const ImVec2& size, const ImVec2& uv0, const ImVec2& uv1, const ImVec4& tint_col, const ImVec4& border_col);
    extern bool ImGuiInputText(const char* label, char* str, int bufferSize, ImGuiInputTextFlags flags, ImGuiInputTextCallback callback, void* user_data);
    extern bool ImGuiInputTextMultiline(const char* label, char* str, int bufferSize, const ImVec2& size, ImGuiInputTextFlags flags, ImGuiInputTextCallback callback, void* user_data);
    extern void ImGuiPlotLines(const char* label, const float* values, int values_count, int values_offset = 0);
    extern void ImGuiProgressBar(float progress, const ImVec2& size_arg = ImVec2(-1,0), const char* overlay = NULL);
    extern void ImGuiProgressBarWithoutLabel(float progress, const ImVec2& size_arg = ImVec2(-1,0));
    extern void ImGuiSetWindowFontScale(float scale);    
    extern bool ImGuiBeginPopupContextItem(const char* id, ImGuiPopupFlags flags);    
    extern void ImGuiEndPopup();
    extern float ImGuiGetFrameHeightWithSpacing();
    extern bool ImGuiBeginChild1(const char* id, const ImVec2& size, bool border, ImGuiWindowFlags flags);
    extern bool ImGuiBeginChild2(ImGuiID id, const ImVec2& size, bool border, ImGuiWindowFlags flags);
    extern bool ImGuiBeginPopupContextWindow();
    extern bool ImGuiBeginPopupContextWindow1(const char* id, ImGuiPopupFlags flags);
    extern bool ImGuiBeginPopupContextWindow2(const char* id, ImGuiMouseButton mb, bool overItems);
    extern bool ImGuiSelectable(const char* label);
    extern bool ImGuiSelectable1(const char* label, bool* selected, ImGuiSelectableFlags flags, const ImVec2& size);
    extern bool ImGuiSelectable2(const char* label, bool selected, ImGuiSelectableFlags flags, const ImVec2& size);
    extern void ImGuiPushStyleVar1(ImGuiStyleVar styleVar, const ImVec2& val);
    extern void ImGuiPushStyleVar2(ImGuiStyleVar styleVar, float val);
    extern void ImGuiPopStyleVar(int count);
    extern void ImGuiLogToClipboard(int autoOpenDepth);
    extern float ImGuiGetScrollY();
    extern float ImGuiGetScrollMaxY();
    extern void ImGuiSetScrollHereY(float centerYRatio);
    extern bool ImGuiIsWindowFocused(ImGuiFocusedFlags flags);
    extern bool ImGuiIsMouseClicked(ImGuiMouseButton mb, bool repeat);
    extern void ImGuiSetItemDefaultFocus();
    extern bool ImGuiMenuItem(const char* label);
    extern bool ImGuiMenuItem1(const char* label, const char* shortcut, bool* selected, bool enabled);
    extern bool ImGuiMenuItem2(const char* label, const char* shortcut, bool selected, bool enabled);
    extern void ImGuiLogFinish();
    extern void ImGuiTextUnformatted(const char* text);
    extern void ImGuiTextUnformatted1(const char* text, const char* textEnd);
    extern void ImGuiEndChild();
    extern void ImGuiSetStyle(const ImGuiStyle& style);
    extern void ImGuiGetStyle(ImGuiStyle* style);
    extern void ImGuiSetIO(const ImGuiIO& io);
    extern void ImGuiGetIO(ImGuiIO* io);
    extern ImFont* ImGuiAddFontFromFileTTF(const char* filepath, float sizePixels);

    extern ConsoleApp* ImGuiConsoleAppCreate();
    extern void ImGuiConsoleAppDispose(ConsoleApp* app);
    extern void ImGuiConsoleAppFree(ConsoleApp* app);
    extern void ImGuiConsoleAppSetCommandCallback(ConsoleApp* app, ProcessCommandCallback callback);
    extern void ImGuiConsoleAppDraw(ConsoleApp* app, const char* title, const ImVec2& position, const ImVec2& size);
    extern void ImGuiConsoleAppAddLog(ConsoleApp* app, const char* message);
    extern void ImGuiConsoleAppClearLog(ConsoleApp* app);
    extern void ImGuiConsoleAppSetFocus(ConsoleApp* app);
}

#endif