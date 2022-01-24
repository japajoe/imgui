#include "imguisharp.h"
#include <iostream>
#include "imgui/imgui.h"

extern "C" bool ImGui_OpenGL3_Init(const char* glsl_version)
{
    return ImGui_ImplOpenGL3_Init(glsl_version);
}

extern "C" bool ImGui_CustomBackend_InitForOpenGL(ImGuiImplCallbackTypes callbacks, ImGuiImplKeybindings keybindings, ImGuiImplCursorType cursorTypes, ImGuiImplMouseButton mouseButtons)
{
    return ImGui_ImplCustom_InitForOpenGL(callbacks, keybindings, cursorTypes, mouseButtons);
}

extern "C" void ImGui_OpenGL3_NewFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
}

extern "C" void ImGui_OpenGL3_RenderDrawData()
{
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

extern "C" void ImGui_OpenGL3_Shutdown()
{
    ImGui_ImplOpenGL3_Shutdown();
}

extern "C" void ImGui_CustomBackend_Shutdown()
{
    ImGui_ImplCustom_Shutdown();
}

extern "C" void ImGui_CustomBackend_NewFrame(const ImGuiImplFrameSettings frameSettings)
{
    ImGui_ImplCustom_NewFrame(frameSettings);
}

extern "C" bool ImGui_CustomBackend_ProcessEvent(const ImGuiImplWindowEventType evnt, const ImGuiImplKeyboardState keyboardState, const ImGuiImplMouseState mouseState, const char* inputText)
{
    return ImGui_ImplCustom_ProcessEvent(evnt, keyboardState, mouseState, inputText);
}

extern "C" void ImGui_Init()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls    
}

extern "C" void ImGui_NewFrame()
{
    ImGui::NewFrame();
}

extern "C" void ImGui_Render()
{
    ImGui::Render();
}

extern "C" void ImGui_DestroyContext()
{
    ImGui::DestroyContext();
}

extern "C" bool ImGuiBegin(const char* id, bool* active, int flags)
{
    return ImGui::Begin(id, active, flags);
}

extern "C" void ImGuiEnd()
{
    ImGui::End();
}

extern "C" void ImGuiSetNextWindowPos(float x, float y)
{
    ImGui::SetNextWindowPos(ImVec2(x, y));
}

extern "C" void ImGuiSetNextWindowSize(float x, float y)
{
    ImGui::SetNextWindowSize(ImVec2(x, y));
}

extern "C" void ImGuiSetCursorPos(const ImVec2& pos)
{
    ImGui::SetCursorPos(pos);
}

extern "C" void ImGuiSetCursorPosX(float x)
{
    ImGui::SetCursorPosX(x);
}

extern "C" void ImGuiPushStyleColor(ImGuiCol idx, const ImVec4& col)
{
    ImGui::PushStyleColor(idx, col);
}

extern "C" void ImGuiPopStyleColor(int count)
{
    ImGui::PopStyleColor(count);
}

extern "C" bool ImGuiIsAnyItemActive()
{
    return ImGui::IsAnyItemActive();
}

extern "C" bool ImGuiIsAnyItemFocused()
{
    return ImGui::IsAnyItemFocused();
}

extern "C" bool ImGuiIsAnyItemHovered()
{
    return ImGui::IsAnyItemHovered();
}

extern "C" void ImGuiSetKeyboardFocusHere(int offset)
{
    ImGui::SetKeyboardFocusHere(offset);
}

extern "C" bool ImGuiCheckbox(const char* text, bool* value)
{
    return ImGui::Checkbox(text, value);
}

extern "C" void ImGuiText(const char* text)
{
    ImGui::Text(text);
}

extern "C" bool ImGuiButton(const char* text, const ImVec2& rect)
{
    return ImGui::Button(text, rect);
}

extern "C" bool ImGuiImageButton(int textureId, const ImVec2& size, const ImVec2& uv0, const ImVec2& uv1, int frame_padding, const ImVec4& bg_col, const ImVec4& tint_col)
{
    return ImGui::ImageButton((void*)(intptr_t)textureId, size, uv0, uv1, frame_padding, bg_col, tint_col);
}

extern "C" bool ImGuiInputFloat(const char* label, float* value, float step, float step_fast, const char* format, int flags)
{
    ImGuiInputTextFlags f = static_cast<ImGuiInputTextFlags>(flags);
    return ImGui::InputFloat(label, value, step, step_fast, format, f);
}

extern "C" bool ImGuiSliderFloat(const char* label, float* value, float v_min, float v_max, const char* format, float power)
{
    return ImGui::SliderFloat(label, value, v_min, v_max, format, power);
}

extern "C" bool ImGuiInputFloat3(const char* label, float* value, int decimal_precision, int flags)
{
    ImGuiInputTextFlags f = static_cast<ImGuiInputTextFlags>(flags);
    std::string precision = "%." + std::to_string(decimal_precision) + "f";
    return ImGui::InputFloat3(label, value, precision.c_str(), f);
}

extern "C" bool ImGuiColorEdit3(const char* label, float* color, int flags)
{
    ImGuiColorEditFlags f = static_cast<ImGuiColorEditFlags>(flags);
    return ImGui::ColorEdit3(label, color, f);
}

extern "C" bool ImGuiColorEdit4(const char* label, float* color, int flags)
{
    ImGuiColorEditFlags f = static_cast<ImGuiColorEditFlags>(flags);
    return ImGui::ColorEdit4(label, color, f);
}

extern "C" void ImGuiImage(int textureId, const ImVec2& size, const ImVec2& uv0, const ImVec2& uv1, const ImVec4& tint_col, const ImVec4& border_col)
{
    ImGui::Image((void*)(intptr_t)textureId, size, uv0, uv1, tint_col, border_col);
}

extern "C" bool ImGuiInputText(const char* label, char* str, int bufferSize, int flags, ImGuiInputTextCallback callback, void* user_data)
{
    ImGuiInputTextFlags f = static_cast<ImGuiInputTextFlags>(flags);
    return ImGui::InputText(label, str, bufferSize, f,  callback, user_data);
}

extern "C" bool ImGuiInputTextMultiline(const char* label, char* str, int bufferSize, const ImVec2& size, int flags, ImGuiInputTextCallback callback, void* user_data)
{
    ImGuiInputTextFlags f = static_cast<ImGuiInputTextFlags>(flags);
    return ImGui::InputTextMultiline(label, str, bufferSize, size, f, callback, user_data);
}

extern "C" void ImGuiPlotLines(const char* label, const float* values, int values_count, int values_offset)
{
    ImGui::PlotLines(label, values, values_count, values_offset);
}

extern "C" void ImGuiProgressBar(float progress, const ImVec2& size_arg, const char* overlay)
{
    ImGui::ProgressBar(progress, size_arg, overlay);
}

extern "C" void ImGuiProgressBarWithoutLabel(float progress, const ImVec2& size_arg)
{
    ImGui::ProgressBarWithoutLabel(progress, size_arg);
}

extern "C" void ImGuiSetWindowFontScale(float scale)
{
    ImGui::SetWindowFontScale(scale);
}

extern "C" bool ImGuiBeginPopupContextItem(const char* id, ImGuiPopupFlags flags)
{
    return ImGui::BeginPopupContextItem(id, flags);
}

extern "C" void ImGuiEndPopup()
{
    ImGui::EndPopup();
}

extern "C" float ImGuiGetFrameHeightWithSpacing()
{
    return ImGui::GetFrameHeightWithSpacing();
}

extern "C" bool ImGuiBeginChild1(const char* id, const ImVec2& size, bool border, ImGuiWindowFlags flags)
{
    return ImGui::BeginChild(id, size, border, flags);
}

extern "C" bool ImGuiBeginChild2(ImGuiID id, const ImVec2& size, bool border, ImGuiWindowFlags flags)
{
    return ImGui::BeginChild(id, size, border, flags);
}

extern "C" bool ImGuiBeginPopupContextWindow()
{
    return ImGui::BeginPopupContextWindow();
}

extern "C" bool ImGuiBeginPopupContextWindow1(const char* id, ImGuiPopupFlags flags)
{
    return ImGui::BeginPopupContextWindow(id, flags);
}

extern "C" bool ImGuiBeginPopupContextWindow2(const char* id, ImGuiMouseButton mb, bool overItems)
{
    return ImGui::BeginPopupContextWindow(id, mb, overItems);
}

extern "C" bool ImGuiSelectable(const char* label)
{
    return ImGui::Selectable(label);
}

extern "C" bool ImGuiSelectable1(const char* label, bool* selected, ImGuiSelectableFlags flags, const ImVec2& size)
{
    return ImGui::Selectable(label, selected, flags, size);
}

extern "C" bool ImGuiSelectable2(const char* label, bool selected, ImGuiSelectableFlags flags, const ImVec2& size)
{
    return ImGui::Selectable(label, selected, flags, size);
}

extern "C" void ImGuiPushStyleVar1(ImGuiStyleVar styleVar, const ImVec2& val)
{
    ImGui::PushStyleVar(styleVar, val);
}

extern "C" void ImGuiPushStyleVar2(ImGuiStyleVar styleVar, float val)
{
    ImGui::PushStyleVar(styleVar, val);
}

extern "C" void ImGuiPopStyleVar(int count)
{
    ImGui::PopStyleVar(count);
}

extern "C" void ImGuiLogToClipboard(int autoOpenDepth)
{
    ImGui::LogToClipboard(autoOpenDepth);
}

extern "C" float ImGuiGetScrollY()
{
    return ImGui::GetScrollY();
}

extern "C" float ImGuiGetScrollMaxY()
{
    return ImGui::GetScrollMaxY();
}

extern "C" void ImGuiSetScrollHereY(float centerYRatio)
{
    ImGui::SetScrollHereY(centerYRatio);
}

extern "C" bool ImGuiIsWindowFocused(ImGuiFocusedFlags flags)
{
    return ImGui::IsWindowFocused(flags);
}

extern "C" bool ImGuiIsMouseClicked(ImGuiMouseButton mb, bool repeat)
{
    return ImGui::IsMouseClicked(mb, repeat);
}

extern "C" void ImGuiSetItemDefaultFocus()
{
    ImGui::SetItemDefaultFocus();
}

extern "C" bool ImGuiMenuItem(const char* label)
{
    return ImGui::MenuItem(label);
}

extern "C" bool ImGuiMenuItem1(const char* label, const char* shortcut, bool* selected, bool enabled)
{
    return ImGui::MenuItem(label, shortcut, selected, enabled);
}

extern "C" bool ImGuiMenuItem2(const char* label, const char* shortcut, bool selected, bool enabled)
{
    return ImGui::MenuItem(label, shortcut, selected, enabled);
}

extern "C" void ImGuiLogFinish()
{
    ImGui::LogFinish();
}

extern "C" void ImGuiTextUnformatted(const char* text)
{
    ImGui::TextUnformatted(text);
}

extern "C" void ImGuiTextUnformatted1(const char* text, const char* textEnd)
{
    ImGui::TextUnformatted(text, textEnd);
}

extern "C" void ImGuiEndChild()
{
    ImGui::EndChild();
}

extern "C" void ImGuiSetStyle(const ImGuiStyle& style)
{
    ImGuiStyle& currentStyle = ImGui::GetStyle();
    currentStyle = style;
}

extern "C" void ImGuiGetStyle(ImGuiStyle* style)
{
    ImGuiStyle& currentStyle = ImGui::GetStyle();
    *style = currentStyle;
}

extern "C" void ImGuiSetIO(const ImGuiIO& io)
{
    ImGuiIO& i_io = ImGui::GetIO();
    i_io = io;
}

extern "C" void ImGuiGetIO(ImGuiIO* io)
{
    ImGuiIO& i_io = ImGui::GetIO();
    *io = i_io;
}

extern "C" ImFont* ImGuiAddFontFromFileTTF(const char* filepath, float sizePixels)
{
    ImGuiIO& io = ImGui::GetIO();
    ImFont* pFont = io.Fonts->AddFontFromFileTTF(filepath, sizePixels);    
    return pFont;
}

extern "C" ConsoleApp* ImGuiConsoleAppCreate()
{
    ConsoleApp* app = new ConsoleApp();
    return app;
}

extern "C" void ImGuiConsoleAppDispose(ConsoleApp* app)
{
    app->Dispose();
}

extern "C" void ImGuiConsoleAppFree(ConsoleApp* app)
{
    if(app != nullptr)
    {
        delete app;
        app = nullptr;
    }
}

extern "C" void ImGuiConsoleAppSetCommandCallback(ConsoleApp* app, ProcessCommandCallback callback)
{
    app->processCommand = callback;
}

extern "C" void ImGuiConsoleAppDraw(ConsoleApp* app, const char* title, const ImVec2& position, const ImVec2& size)
{
    bool open = true;
    app->Draw(title, &open, position, size);
}

extern "C" void ImGuiConsoleAppAddLog(ConsoleApp* app, const char* message)
{
    app->AddLog(message);
}

extern "C" void ImGuiConsoleAppClearLog(ConsoleApp* app)
{
    app->ClearLog();
}

extern "C" void ImGuiConsoleAppSetFocus(ConsoleApp* app)
{
    app->SetFocus();
}