#ifndef IMGUISHARP_H
#define IMGUISHARP_H

#include "librarydefinitions.h"
#include "imgui/imgui_impl_custom.h"
#include "imgui/imgui_impl_opengl3.h"
#include "ConsoleApp.h"
#include <string>

extern "C" IMGUI_API_EXPORT bool ImGui_OpenGL3_Init(const char* glsl_version);
extern "C" IMGUI_API_EXPORT void ImGui_OpenGL3_NewFrame();    
extern "C" IMGUI_API_EXPORT void ImGui_OpenGL3_RenderDrawData();
extern "C" IMGUI_API_EXPORT void ImGui_OpenGL3_Shutdown();	

extern "C" IMGUI_API_EXPORT bool ImGui_CustomBackend_InitForOpenGL(ImGuiImplCallbackTypes callbacks, ImGuiImplKeybindings keybindings, ImGuiImplCursorType cursorTypes, ImGuiImplMouseButton mouseButtons);
extern "C" IMGUI_API_EXPORT void ImGui_CustomBackend_Shutdown();
extern "C" IMGUI_API_EXPORT void ImGui_CustomBackend_NewFrame(const ImGuiImplFrameSettings frameSettings);
extern "C" IMGUI_API_EXPORT bool ImGui_CustomBackend_ProcessEvent(const ImGuiImplWindowEventType evnt, const ImGuiImplKeyboardState keyboardState, const ImGuiImplMouseState mouseState, const char* inputText);

extern "C" IMGUI_API_EXPORT void ImGui_Init();
extern "C" IMGUI_API_EXPORT void ImGui_NewFrame();
extern "C" IMGUI_API_EXPORT void ImGui_Render();
extern "C" IMGUI_API_EXPORT void ImGui_DestroyContext();

extern "C" IMGUI_API_EXPORT bool ImGuiBegin(const char* id, bool* active, ImGuiWindowFlags flags);
extern "C" IMGUI_API_EXPORT void ImGuiEnd();
extern "C" IMGUI_API_EXPORT void ImGuiSetNextWindowPos(float x, float y);
extern "C" IMGUI_API_EXPORT void ImGuiSetNextWindowSize(float x, float y);
extern "C" IMGUI_API_EXPORT void ImGuiSetCursorPos(const ImVec2& pos);
extern "C" IMGUI_API_EXPORT void ImGuiSetCursorPosX(float x);
extern "C" IMGUI_API_EXPORT void ImGuiPushStyleColor(ImGuiCol idx, const ImVec4& col);
extern "C" IMGUI_API_EXPORT void ImGuiPopStyleColor(int count = 1);
extern "C" IMGUI_API_EXPORT void ImGuiPushFont(ImFont* font);
extern "C" IMGUI_API_EXPORT void ImGuiPopFont();
extern "C" IMGUI_API_EXPORT bool ImGuiIsAnyItemActive();
extern "C" IMGUI_API_EXPORT bool ImGuiIsAnyItemFocused();
extern "C" IMGUI_API_EXPORT bool ImGuiIsAnyItemHovered();
extern "C" IMGUI_API_EXPORT void ImGuiSetKeyboardFocusHere(int offset);
extern "C" IMGUI_API_EXPORT bool ImGuiCheckbox(const char* text, bool* value);
extern "C" IMGUI_API_EXPORT void ImGuiText(const char* text);
extern "C" IMGUI_API_EXPORT bool ImGuiButton(const char* text, const ImVec2& rect);
extern "C" IMGUI_API_EXPORT bool ImGuiImageButton(int textureId, const ImVec2& size, const ImVec2& uv0, const ImVec2& uv1, int frame_padding, const ImVec4& bg_col, const ImVec4& tint_col);
extern "C" IMGUI_API_EXPORT bool ImGuiSliderFloat(const char* label, float* value, float v_min, float v_max, const char* format, float power);
extern "C" IMGUI_API_EXPORT bool ImGuiInputFloat(const char* label, float* value, float step, float step_fast, const char* format, ImGuiInputTextFlags flags);
extern "C" IMGUI_API_EXPORT bool ImGuiInputFloat2(const char* label, float* value, int decimal_precision, ImGuiInputTextFlags flags);
extern "C" IMGUI_API_EXPORT bool ImGuiInputFloat3(const char* label, float* value, int decimal_precision, ImGuiInputTextFlags flags);
extern "C" IMGUI_API_EXPORT bool ImGuiInputFloat4(const char* label, float* value, int decimal_precision, ImGuiInputTextFlags flags);
extern "C" IMGUI_API_EXPORT bool ImGuiInputDouble(const char* label, double* value, double step, double step_fast, const char* format, ImGuiInputTextFlags flags);
extern "C" IMGUI_API_EXPORT bool ImGuiInputInt(const char* label, int* value, double step, double step_fast, const char* format, ImGuiInputTextFlags flags);
extern "C" IMGUI_API_EXPORT bool ImGuiInputInt2(const char* label, int* value, ImGuiInputTextFlags flags);
extern "C" IMGUI_API_EXPORT bool ImGuiInputInt3(const char* label, int* value, ImGuiInputTextFlags flags);
extern "C" IMGUI_API_EXPORT bool ImGuiInputInt4(const char* label, int* value, ImGuiInputTextFlags flags);
extern "C" IMGUI_API_EXPORT bool ImGuiColorEdit3(const char* label, float* color, ImGuiColorEditFlags flags);
extern "C" IMGUI_API_EXPORT bool ImGuiColorEdit4(const char* label, float* color, ImGuiColorEditFlags flags);
extern "C" IMGUI_API_EXPORT void ImGuiImage(int textureId, const ImVec2& size, const ImVec2& uv0, const ImVec2& uv1, const ImVec4& tint_col, const ImVec4& border_col);
extern "C" IMGUI_API_EXPORT bool ImGuiInputText(const char* label, char* str, int bufferSize, ImGuiInputTextFlags flags, ImGuiInputTextCallback callback, void* user_data);
extern "C" IMGUI_API_EXPORT bool ImGuiInputTextMultiline(const char* label, char* str, int bufferSize, const ImVec2& size, ImGuiInputTextFlags flags, ImGuiInputTextCallback callback, void* user_data);
extern "C" IMGUI_API_EXPORT void ImGuiPlotLines(const char* label, const float* values, int values_count, int values_offset = 0);
extern "C" IMGUI_API_EXPORT void ImGuiProgressBar(float progress, const ImVec2& size_arg = ImVec2(-1,0), const char* overlay = NULL);
extern "C" IMGUI_API_EXPORT void ImGuiProgressBarWithoutLabel(float progress, const ImVec2& size_arg = ImVec2(-1,0));
extern "C" IMGUI_API_EXPORT void ImGuiSetWindowFontScale(float scale);    
extern "C" IMGUI_API_EXPORT bool ImGuiBeginPopupContextItem(const char* id, ImGuiPopupFlags flags);    
extern "C" IMGUI_API_EXPORT void ImGuiEndPopup();
extern "C" IMGUI_API_EXPORT float ImGuiGetFrameHeightWithSpacing();
extern "C" IMGUI_API_EXPORT bool ImGuiBeginChild1(const char* id, const ImVec2& size, bool border, ImGuiWindowFlags flags);
extern "C" IMGUI_API_EXPORT bool ImGuiBeginChild2(ImGuiID id, const ImVec2& size, bool border, ImGuiWindowFlags flags);
extern "C" IMGUI_API_EXPORT bool ImGuiBeginPopupContextWindow();
extern "C" IMGUI_API_EXPORT bool ImGuiBeginPopupContextWindow1(const char* id, ImGuiPopupFlags flags);
extern "C" IMGUI_API_EXPORT bool ImGuiBeginPopupContextWindow2(const char* id, ImGuiMouseButton mb, bool overItems);
extern "C" IMGUI_API_EXPORT bool ImGuiSelectable(const char* label);
extern "C" IMGUI_API_EXPORT bool ImGuiSelectable1(const char* label, bool* selected, ImGuiSelectableFlags flags, const ImVec2& size);
extern "C" IMGUI_API_EXPORT bool ImGuiSelectable2(const char* label, bool selected, ImGuiSelectableFlags flags, const ImVec2& size);
extern "C" IMGUI_API_EXPORT void ImGuiPushStyleVar1(ImGuiStyleVar styleVar, const ImVec2& val);
extern "C" IMGUI_API_EXPORT void ImGuiPushStyleVar2(ImGuiStyleVar styleVar, float val);
extern "C" IMGUI_API_EXPORT void ImGuiPopStyleVar(int count);
extern "C" IMGUI_API_EXPORT void ImGuiLogToClipboard(int autoOpenDepth);
extern "C" IMGUI_API_EXPORT float ImGuiGetScrollY();
extern "C" IMGUI_API_EXPORT float ImGuiGetScrollMaxY();
extern "C" IMGUI_API_EXPORT void ImGuiSetScrollHereY(float centerYRatio);
extern "C" IMGUI_API_EXPORT bool ImGuiIsWindowFocused(ImGuiFocusedFlags flags);
extern "C" IMGUI_API_EXPORT bool ImGuiIsMouseClicked(ImGuiMouseButton mb, bool repeat);
extern "C" IMGUI_API_EXPORT void ImGuiSetItemDefaultFocus();
extern "C" IMGUI_API_EXPORT bool ImGuiMenuItem(const char* label);
extern "C" IMGUI_API_EXPORT bool ImGuiMenuItem1(const char* label, const char* shortcut, bool* selected, bool enabled);
extern "C" IMGUI_API_EXPORT bool ImGuiMenuItem2(const char* label, const char* shortcut, bool selected, bool enabled);
extern "C" IMGUI_API_EXPORT void ImGuiLogFinish();
extern "C" IMGUI_API_EXPORT void ImGuiTextUnformatted(const char* text);
extern "C" IMGUI_API_EXPORT void ImGuiTextUnformatted1(const char* text, const char* textEnd);
extern "C" IMGUI_API_EXPORT void ImGuiEndChild();
extern "C" IMGUI_API_EXPORT bool ImGuiBeginCombo(const char* label, const char* previewValue, ImGuiComboFlags flags);
extern "C" IMGUI_API_EXPORT void ImGuiEndCombo();
extern "C" IMGUI_API_EXPORT void ImGuiSetStyle(const ImGuiStyle& style);
extern "C" IMGUI_API_EXPORT void ImGuiGetStyle(ImGuiStyle* style);
extern "C" IMGUI_API_EXPORT void ImGuiSetIO(const ImGuiIO& io);
extern "C" IMGUI_API_EXPORT void ImGuiGetIO(ImGuiIO* io);
extern "C" IMGUI_API_EXPORT ImFont* ImGuiAddFontFromFileTTF(const char* filepath, float sizePixels);

extern "C" IMGUI_API_EXPORT ConsoleApp* ImGuiConsoleAppCreate();
extern "C" IMGUI_API_EXPORT void ImGuiConsoleAppDispose(ConsoleApp* app);
extern "C" IMGUI_API_EXPORT void ImGuiConsoleAppFree(ConsoleApp* app);
extern "C" IMGUI_API_EXPORT void ImGuiConsoleAppSetCommandCallback(ConsoleApp* app, ProcessCommandCallback callback);
extern "C" IMGUI_API_EXPORT void ImGuiConsoleAppDraw(ConsoleApp* app, const char* title, const ImVec2& position, const ImVec2& size);
extern "C" IMGUI_API_EXPORT void ImGuiConsoleAppAddLog(ConsoleApp* app, const char* message);
extern "C" IMGUI_API_EXPORT void ImGuiConsoleAppClearLog(ConsoleApp* app);
extern "C" IMGUI_API_EXPORT void ImGuiConsoleAppSetFocus(ConsoleApp* app);

#endif