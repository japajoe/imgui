# imgui
Cross platform native library for Dear ImGui

This library is made to make it easier to create different language bindings for Dear ImGui. I specifically created it because I wanted to use ImGui in my C# applications, but I found ImGui.NET overly complicated to get to work on Linux. In fact I couldn't get it to work at all. This library does not have bindings for all functions that ImGui offers, but I limited it to a subset of functions that I needed the most. You are free to add more if you like! I have built and tested this on Linux Mint 18.3, Windows 7 and Windows 10. Unfortunately I have no way to build and/or test on Mac but in theory it should compile on it as well.

Since ImGui relies on a graphics back-end, I have chosen to include the source of GLEW so this library has no external dependencies. I do not plan to add support for DirectX/Vulkan and/or Metal because I do not use any of them. I only use OpenGL and as such you'll have to add support for other graphics libraries yourself if you wish to use them. Note that this version of ImGui only works with OpenGL 3.3 and up.

I did add a agnostic windowing library back-end so you can use any windowing library you prefer, provided you implement all needed callbacks yourself. I have tested this with SDL and GTK, but there's no reason you can't use GLFW or any other library of your choice. See imgui_impl_custom.cpp to get an idea of what to implement.

For a working example see https://github.com/japajoe/SkylineEngine (specifically https://github.com/japajoe/SkylineEngine/blob/main/DearImGui/ImGuiControl.cs and https://github.com/japajoe/SkylineEngine/blob/main/SkylineEngine/Application.cs).
