#include "imguisharp.h"
#include <iostream>
#include "imgui/imgui.h"

bool ImGui_OpenGL3_Init(const char* glsl_version)
{
    return ImGui_ImplOpenGL3_Init(glsl_version);
}

bool ImGui_CustomBackend_InitForOpenGL(ImGuiImplCallbackTypes callbacks, ImGuiImplKeybindings keybindings, ImGuiImplCursorType cursorTypes, ImGuiImplMouseButton mouseButtons)
{
    return ImGui_ImplCustom_InitForOpenGL(callbacks, keybindings, cursorTypes, mouseButtons);
}

void ImGui_OpenGL3_NewFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
}

void ImGui_OpenGL3_RenderDrawData()
{
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void ImGui_OpenGL3_Shutdown()
{
    ImGui_ImplOpenGL3_Shutdown();
}

void ImGui_CustomBackend_Shutdown()
{
    ImGui_ImplCustom_Shutdown();
}

void ImGui_CustomBackend_NewFrame(const ImGuiImplFrameSettings frameSettings)
{
    ImGui_ImplCustom_NewFrame(frameSettings);
}

bool ImGui_CustomBackend_ProcessEvent(const ImGuiImplWindowEventType evnt, const ImGuiImplKeyboardState keyboardState, const ImGuiImplMouseState mouseState, const char* inputText)
{
    return ImGui_ImplCustom_ProcessEvent(evnt, keyboardState, mouseState, inputText);
}

void ImGui_Init()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls    
}

void ImGui_NewFrame()
{
    ImGui::NewFrame();
}

void ImGui_Render()
{
    ImGui::Render();
}

void ImGui_DestroyContext()
{
    ImGui::DestroyContext();
}

void ImGuiDebugStuff()
{
    std::cout << "ImFontConfig size: " << sizeof(ImFontConfig) << std::endl;
    std::cout << "[FieldOffset(" << offsetof(ImFontConfig, FontData) << ")] FontData" << std::endl;
    std::cout << "[FieldOffset(" << offsetof(ImFontConfig, FontDataSize) << ")] FontDataSize" << std::endl;
    std::cout << "[FieldOffset(" << offsetof(ImFontConfig, FontDataOwnedByAtlas) << ")] FontDataOwnedByAtlas" << std::endl;
    std::cout << "[FieldOffset(" << offsetof(ImFontConfig, FontNo) << ")] FontNo" << std::endl;
    std::cout << "[FieldOffset(" << offsetof(ImFontConfig, SizePixels) << ")] SizePixels" << std::endl;
    std::cout << "[FieldOffset(" << offsetof(ImFontConfig, OversampleH) << ")] OversampleH" << std::endl;
    std::cout << "[FieldOffset(" << offsetof(ImFontConfig, OversampleV) << ")] OversampleV" << std::endl;
    std::cout << "[FieldOffset(" << offsetof(ImFontConfig, PixelSnapH) << ")] PixelSnapH" << std::endl;
    std::cout << "[FieldOffset(" << offsetof(ImFontConfig, GlyphExtraSpacing) << ")] GlyphExtraSpacing" << std::endl;
    std::cout << "[FieldOffset(" << offsetof(ImFontConfig, GlyphOffset) << ")] GlyphOffset" << std::endl;
    std::cout << "[FieldOffset(" << offsetof(ImFontConfig, GlyphRanges) << ")] GlyphRanges" << std::endl;
    std::cout << "[FieldOffset(" << offsetof(ImFontConfig, GlyphMinAdvanceX) << ")] GlyphMinAdvanceX" << std::endl;
    std::cout << "[FieldOffset(" << offsetof(ImFontConfig, GlyphMaxAdvanceX) << ")] GlyphMaxAdvanceX" << std::endl;
    std::cout << "[FieldOffset(" << offsetof(ImFontConfig, MergeMode) << ")] MergeMode" << std::endl;
    std::cout << "[FieldOffset(" << offsetof(ImFontConfig, RasterizerFlags) << ")] RasterizerFlags" << std::endl;
    std::cout << "[FieldOffset(" << offsetof(ImFontConfig, RasterizerMultiply) << ")] RasterizerMultiply" << std::endl;
    std::cout << "[FieldOffset(" << offsetof(ImFontConfig, EllipsisChar) << ")] EllipsisChar" << std::endl;
    std::cout << "[FieldOffset(" << offsetof(ImFontConfig, Name) << ")] Name" << std::endl;
    std::cout << "[FieldOffset(" << offsetof(ImFontConfig, DstFont) << ")] DstFont" << std::endl;
}

bool ImGuiBegin(const char* id, bool* active, ImGuiWindowFlags flags)
{
    return ImGui::Begin(id, active, flags);
}

void ImGuiEnd()
{
    ImGui::End();
}

void ImGuiSetNextWindowPos(float x, float y)
{
    ImGui::SetNextWindowPos(ImVec2(x, y));
}

void ImGuiSetNextWindowSize(float x, float y)
{
    ImGui::SetNextWindowSize(ImVec2(x, y));
}

void ImGuiSetCursorPos(const ImVec2& pos)
{
    ImGui::SetCursorPos(pos);
}

void ImGuiSetCursorPosX(float x)
{
    ImGui::SetCursorPosX(x);
}

void ImGuiPushStyleColor(ImGuiCol idx, const ImVec4& col)
{
    ImGui::PushStyleColor(idx, col);
}

void ImGuiPopStyleColor(int count)
{
    ImGui::PopStyleColor(count);
}

bool ImGuiIsAnyItemActive()
{
    return ImGui::IsAnyItemActive();
}

bool ImGuiIsAnyItemFocused()
{
    return ImGui::IsAnyItemFocused();
}

bool ImGuiIsAnyItemHovered()
{
    return ImGui::IsAnyItemHovered();
}

void ImGuiSetKeyboardFocusHere(int offset)
{
    ImGui::SetKeyboardFocusHere(offset);
}

bool ImGuiCheckbox(const char* text, bool* value)
{
    return ImGui::Checkbox(text, value);
}

void ImGuiText(const char* text)
{
    ImGui::Text(text);
}

bool ImGuiButton(const char* text, const ImVec2& rect)
{
    return ImGui::Button(text, rect);
}

bool ImGuiImageButton(int textureId, const ImVec2& size, const ImVec2& uv0, const ImVec2& uv1, int frame_padding, const ImVec4& bg_col, const ImVec4& tint_col)
{
    return ImGui::ImageButton((void*)(intptr_t)textureId, size, uv0, uv1, frame_padding, bg_col, tint_col);
}

bool ImGuiSliderFloat(const char* label, float* value, float v_min, float v_max, const char* format, ImGuiSliderFlags flags)
{    
    return ImGui::SliderFloat(label, value, v_min, v_max, format, flags);
}

bool ImGuiInputFloat(const char* label, float* value, float step, float step_fast, const char* format, ImGuiInputTextFlags flags)
{
    return ImGui::InputFloat(label, value, step, step_fast, format, flags);
}

bool ImGuiInputFloat2(const char* label, float* value, int decimal_precision, ImGuiInputTextFlags flags)
{
    std::string precision = "%." + std::to_string(decimal_precision) + "f";
    return ImGui::InputFloat2(label, value, precision.c_str(), flags);
}

bool ImGuiInputFloat3(const char* label, float* value, int decimal_precision, ImGuiInputTextFlags flags)
{
    std::string precision = "%." + std::to_string(decimal_precision) + "f";
    return ImGui::InputFloat3(label, value, precision.c_str(), flags);
}

bool ImGuiInputFloat4(const char* label, float* value, int decimal_precision, ImGuiInputTextFlags flags)
{
    std::string precision = "%." + std::to_string(decimal_precision) + "f";
    return ImGui::InputFloat4(label, value, precision.c_str(), flags);
}

bool ImGuiInputDouble(const char* label, double* value, double step, double step_fast, const char* format, ImGuiInputTextFlags flags)
{
    return ImGui::InputDouble(label, value, step, step_fast, format, flags);
}

bool ImGuiInputInt(const char* label, int* value, double step, double step_fast, const char* format, ImGuiInputTextFlags flags)
{
    return ImGui::InputInt(label, value, step, step_fast, flags);
}

bool ImGuiInputInt2(const char* label, int* value, ImGuiInputTextFlags flags)
{
    return ImGui::InputInt2(label, value, flags);
}

bool ImGuiInputInt3(const char* label, int* value, ImGuiInputTextFlags flags)
{
    return ImGui::InputInt3(label, value, flags);
}

bool ImGuiInputInt4(const char* label, int* value, ImGuiInputTextFlags flags)
{
    return ImGui::InputInt4(label, value, flags);
}

bool ImGuiColorEdit3(const char* label, float* color, ImGuiColorEditFlags flags)
{
    return ImGui::ColorEdit3(label, color, flags);
}

bool ImGuiColorEdit4(const char* label, float* color, ImGuiColorEditFlags flags)
{
    return ImGui::ColorEdit4(label, color, flags);
}

void ImGuiImage(int textureId, const ImVec2& size, const ImVec2& uv0, const ImVec2& uv1, const ImVec4& tint_col, const ImVec4& border_col)
{
    ImGui::Image((void*)(intptr_t)textureId, size, uv0, uv1, tint_col, border_col);
}

bool ImGuiInputText(const char* label, char* str, int bufferSize, ImGuiInputTextFlags flags, ImGuiInputTextCallback callback, void* user_data)
{
    return ImGui::InputText(label, str, bufferSize, flags,  callback, user_data);
}

bool ImGuiInputTextMultiline(const char* label, char* str, int bufferSize, const ImVec2& size, ImGuiInputTextFlags flags, ImGuiInputTextCallback callback, void* user_data)
{
    return ImGui::InputTextMultiline(label, str, bufferSize, size, flags, callback, user_data);
}

void ImGuiPlotLines(const char* label, const float* values, int values_count, int values_offset)
{
    ImGui::PlotLines(label, values, values_count, values_offset);
}

void ImGuiProgressBar(float progress, const ImVec2& size_arg, const char* overlay)
{
    ImGui::ProgressBar(progress, size_arg, overlay);
}

void ImGuiProgressBarWithoutLabel(float progress, const ImVec2& size_arg)
{
    ImGui::ProgressBarWithoutLabel(progress, size_arg);
}

void ImGuiSetWindowFontScale(float scale)
{
    ImGui::SetWindowFontScale(scale);
}

bool ImGuiBeginPopupContextItem(const char* id, ImGuiPopupFlags flags)
{
    return ImGui::BeginPopupContextItem(id, flags);
}

void ImGuiEndPopup()
{
    ImGui::EndPopup();
}

float ImGuiGetFrameHeightWithSpacing()
{
    return ImGui::GetFrameHeightWithSpacing();
}

bool ImGuiBeginChild1(const char* id, const ImVec2& size, bool border, ImGuiWindowFlags flags)
{
    return ImGui::BeginChild(id, size, border, flags);
}

bool ImGuiBeginChild2(ImGuiID id, const ImVec2& size, bool border, ImGuiWindowFlags flags)
{
    return ImGui::BeginChild(id, size, border, flags);
}

bool ImGuiBeginPopupContextWindow()
{
    return ImGui::BeginPopupContextWindow();
}

bool ImGuiBeginPopupContextWindow1(const char* id, ImGuiPopupFlags flags)
{
    return ImGui::BeginPopupContextWindow(id, flags);
}

bool ImGuiBeginPopupContextWindow2(const char* id, ImGuiMouseButton mb, bool overItems)
{
    return ImGui::BeginPopupContextWindow(id, mb, overItems);
}

bool ImGuiSelectable(const char* label)
{
    return ImGui::Selectable(label);
}

bool ImGuiSelectable1(const char* label, bool* selected, ImGuiSelectableFlags flags, const ImVec2& size)
{
    return ImGui::Selectable(label, selected, flags, size);
}

bool ImGuiSelectable2(const char* label, bool selected, ImGuiSelectableFlags flags, const ImVec2& size)
{
    return ImGui::Selectable(label, selected, flags, size);
}

void ImGuiPushStyleVar1(ImGuiStyleVar styleVar, const ImVec2& val)
{
    ImGui::PushStyleVar(styleVar, val);
}

void ImGuiPushStyleVar2(ImGuiStyleVar styleVar, float val)
{
    ImGui::PushStyleVar(styleVar, val);
}

void ImGuiPopStyleVar(int count)
{
    ImGui::PopStyleVar(count);
}

void ImGuiPushFont(ImFont* font)
{
    ImGui::PushFont(font);
}

void ImGuiPopFont()
{
    ImGui::PopFont();
}

void ImGuiLogToClipboard(int autoOpenDepth)
{
    ImGui::LogToClipboard(autoOpenDepth);
}

float ImGuiGetScrollY()
{
    return ImGui::GetScrollY();
}

float ImGuiGetScrollMaxY()
{
    return ImGui::GetScrollMaxY();
}

void ImGuiSetScrollHereY(float centerYRatio)
{
    ImGui::SetScrollHereY(centerYRatio);
}

bool ImGuiIsWindowFocused(ImGuiFocusedFlags flags)
{
    return ImGui::IsWindowFocused(flags);
}

bool ImGuiIsMouseClicked(ImGuiMouseButton mb, bool repeat)
{
    return ImGui::IsMouseClicked(mb, repeat);
}

void ImGuiSetItemDefaultFocus()
{
    ImGui::SetItemDefaultFocus();
}

bool ImGuiMenuItem(const char* label)
{
    return ImGui::MenuItem(label);
}

bool ImGuiMenuItem1(const char* label, const char* shortcut, bool* selected, bool enabled)
{
    return ImGui::MenuItem(label, shortcut, selected, enabled);
}

bool ImGuiMenuItem2(const char* label, const char* shortcut, bool selected, bool enabled)
{
    return ImGui::MenuItem(label, shortcut, selected, enabled);
}

void ImGuiLogFinish()
{
    ImGui::LogFinish();
}

void ImGuiTextUnformatted(const char* text)
{
    ImGui::TextUnformatted(text);
}

void ImGuiTextUnformatted1(const char* text, const char* textEnd)
{
    ImGui::TextUnformatted(text, textEnd);
}

void ImGuiEndChild()
{
    ImGui::EndChild();
}

bool ImGuiBeginCombo(const char* label, const char* previewValue, ImGuiComboFlags flags)
{
    return ImGui::BeginCombo(label, previewValue, flags);
}

void ImGuiEndCombo()
{
    ImGui::EndCombo();
}

void ImGuiSetStyle(const ImGuiStyle& style)
{
    ImGuiStyle& currentStyle = ImGui::GetStyle();
    currentStyle = style;
}

void ImGuiGetStyle(ImGuiStyle* style)
{
    ImGuiStyle& currentStyle = ImGui::GetStyle();
    *style = currentStyle;
}

void ImGuiSetIO(const ImGuiIO& io)
{
    ImGuiIO& i_io = ImGui::GetIO();
    i_io = io;
}

void ImGuiGetIO(ImGuiIO* io)
{
    ImGuiIO& i_io = ImGui::GetIO();
    *io = i_io;
}

ImFont* ImGuiAddFontFromFileTTF(const char* filepath, float sizePixels)
{
    ImGuiIO& io = ImGui::GetIO();
    ImFont* pFont = io.Fonts->AddFontFromFileTTF(filepath, sizePixels);    
    return pFont;
}

ImFont* ImGuiAddFontFromMemoryTTF(void* font_data, int font_size, float size_pixels)
{
    ImGuiIO& io = ImGui::GetIO();
    ImFontConfig font_cfg;
    font_cfg.FontDataOwnedByAtlas = false;
    ImFont* pFont = io.Fonts->AddFontFromMemoryTTF(font_data, font_size, size_pixels, &font_cfg);
    return pFont;
}

ConsoleApp* ImGuiConsoleAppCreate()
{
    ConsoleApp* app = new ConsoleApp();
    return app;
}

void ImGuiConsoleAppDispose(ConsoleApp* app)
{
    app->Dispose();
}

void ImGuiConsoleAppFree(ConsoleApp* app)
{
    if(app != nullptr)
    {
        delete app;
        app = nullptr;
    }
}

void ImGuiConsoleAppSetCommandCallback(ConsoleApp* app, ProcessCommandCallback callback)
{
    app->processCommand = callback;
}

void ImGuiConsoleAppDraw(ConsoleApp* app, const char* title, const ImVec2& position, const ImVec2& size)
{
    bool open = true;
    app->Draw(title, &open, position, size);
}

void ImGuiConsoleAppAddLog(ConsoleApp* app, const char* message)
{
    app->AddLog(message);
}

void ImGuiConsoleAppClearLog(ConsoleApp* app)
{
    app->ClearLog();
}

void ImGuiConsoleAppSetFocus(ConsoleApp* app)
{
    app->SetFocus();
}