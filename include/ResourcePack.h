// License (OLC-3)
// Copyright 2018-2021 OneLoneCoder.com
// Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
//     Redistributions or derivations of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
//     Redistributions or derivative works in binary form must reproduce the above copyright notice. This list of conditions and the following disclaimer must be reproduced in the documentation and/or other materials provided with the distribution.
//     Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef RESOURCEPACK_HPP
#define RESOURCEPACK_HPP

#include "librarydefinitions.h"
#include <vector>
#include <stdint.h>
#include <streambuf>
#include <string>
#include <fstream>
#include <map>
#include <vector>

enum class ResultCode 
{ 
    FAIL = 0, 
    OK = 1, 
    NO_FILE = -1
};

struct ResourceBuffer : public std::streambuf
{
    ResourceBuffer(std::ifstream& ifs, uint32_t offset, uint32_t size);
    std::vector<char> vMemory;
};

class ResourcePack : public std::streambuf
{
public:
    ResourcePack();
    ~ResourcePack();
    bool AddFile(const std::string& sFile);
    bool LoadPack(const std::string& sFile, const std::string& sKey);
    bool SavePack(const std::string& sFile, const std::string& sKey);
    ResourceBuffer* GetFileBuffer(const std::string& sFile);
    void GetFileOffset(const std::string& sFile, uint32_t* offset, uint32_t* size);
    bool Loaded();
    std::vector<std::string> ListFiles();	
	ResultCode RemoveFile(const std::string &sFilename);
	ResultCode RenameFile(const std::string &src, const std::string &dest);
    bool FileExistsInMap(const std::string& sFilename);
private:
    struct sResourceFile { uint32_t nSize; uint32_t nOffset; };
    std::map<std::string, sResourceFile> mapFiles;
    std::ifstream baseFile;
    std::vector<char> scramble(const std::vector<char>& data, const std::string& key);
    std::string makeposix(const std::string& path);
};

extern "C" IMGUI_API_EXPORT ResourcePack* ResourcePackCreate();
extern "C" IMGUI_API_EXPORT void ResourcePackDispose(ResourcePack* p);
extern "C" IMGUI_API_EXPORT bool ResourcePackAddFile(ResourcePack* p, const char* sFile);
extern "C" IMGUI_API_EXPORT bool ResourcePackLoadPack(ResourcePack* p, const char* sFile, const char* sKey);
extern "C" IMGUI_API_EXPORT bool ResourcePackSavePack(ResourcePack* p, const char* sFile, const char* sKey);
extern "C" IMGUI_API_EXPORT bool ResourcePackIsLoaded(ResourcePack* p);
extern "C" IMGUI_API_EXPORT char** ResourcePackListFiles(ResourcePack* p, int* numFiles);
extern "C" IMGUI_API_EXPORT void ResourcePackFreeStringArray(char** s, int numStrings);
extern "C" IMGUI_API_EXPORT ResultCode ResourcePackRemoveFile(ResourcePack* p, const char* sFile);
extern "C" IMGUI_API_EXPORT ResultCode ResourcePackRenameFile(ResourcePack* p, const char* src, const char* dest);
extern "C" IMGUI_API_EXPORT ResourceBuffer* ResourcePackFileBufferGet(ResourcePack* p, const char* sFile);
extern "C" IMGUI_API_EXPORT void ResourcePackFileGetOffset(ResourcePack* p, const char* sFile, uint32_t* offset, uint32_t* size);
extern "C" IMGUI_API_EXPORT bool ResourcePackFileExistsInMap(ResourcePack* p, const char* filename);
extern "C" IMGUI_API_EXPORT void ResourcePackFileBufferDispose(ResourceBuffer* b);
extern "C" IMGUI_API_EXPORT uint32_t ResourcePackFileBufferGetSize(ResourceBuffer* b);
extern "C" IMGUI_API_EXPORT char* ResourcePackFileBufferGetData(ResourceBuffer* b);

#endif
