#include "pch.h"
#include "Shape.h"

Shape::Shape()
{
    width = 0;
    height = 0;
    buffer = nullptr;
}

Shape::Shape(const Shape& rhs)
{
    width = rhs.width;
    height = rhs.height;
    int len = width * height;
    buffer = new WCHAR[len];
    wmemcpy(rhs.buffer, buffer, len);   // 범위할당
}

Shape::~Shape()
{
    if (buffer)
    {
        delete[] buffer;
        buffer = nullptr;
    }
}

Shape* Shape::LoadShape(const wstring& fileName)
{
    /*
    WCHAR path[MAX_PATH] = { 0, };
    GetModuleFileNameW(NULL, path, MAX_PATH);

    wstring wpath = path;
    for (int i = MAX_PATH - 1; i >= 0; i--)
    {
        if (path[i] == L'\\')
        {
            wpath = wpath.substr(0,i+1)+fileName;   // i+1 은 백슬래시 1개 포함.
            break;
        }
    }

    FILE* fp;
    _wfopen_s(&fp, wpath.c_str(), L"rt");
    if (fp == nullptr)
    {
        return nullptr;
    }

    fseek(fp, 0, SEEK_END); // Seek, 파일끝으로 옮긴 이유, 총 길이를 위함
    int len = ftell(fp) - 1;    //FilePointer의 위치값 리턴, -1은 EOF
    fseek(fp, 0, SEEK_SET);

    WCHAR bom = 0;  // Byte Order Mark : 인코딩 방식 저장
    fread(&bom, sizeof(WCHAR), 1, fp);
    if (bom != 0xFEFF)   // UTF-16, Big Endian   
    {
        return nullptr;
    }

    int bufCount = len / 2 + 1;
    WCHAR* buf = new WCHAR[bufCount];
    wmemset(buf, 0, bufCount);
    fread(buf, sizeof(WCHAR), bufCount, fp);
    buf[len / 2] = L'\0';   // Last Index

    fclose(fp);

    // Parsing
    int width = 0;
    int height = 0;
    int col = 0;
    int line = 1;
    for (int i = 0; i < bufCount; i++)
    {
        if (buf[i] == L'\r')    // Carage Return, Line Feed
        {
            if (width == 0)
            {
                width = i;
            }
            line++; //개행이 발생하면 Y축이 증가함(height++)
        }
    }

    width = width == 0 ? 1 : width;
    height = line;

    WCHAR* data = new WCHAR[width * height];
    int index = 0;

    for (int i = 0; i < bufCount; i++)
    {
        if (buf[i] == L'\r') continue;
        if (buf[i] == L'\n') continue;
        if (buf[i] == L'\0') continue;
        data[index] = buf[i];
        index++;
    }

    delete[] buf;

    Shape* shape = new Shape();
    shape->buffer = data;
    shape->width = width;
    shape->height = height;

    return shape;
    */

    WCHAR path[MAX_PATH] = { 0, };
    GetModuleFileNameW(NULL, path, MAX_PATH);

    wstring wpath = path;
    for (int i = MAX_PATH - 1; i >= 0; i--)
    {
        if (path[i] == L'\\')
        {
            wpath = wpath.substr(0, i + 1) + fileName;
            break;
        }
    }

    FILE* fp;
    _wfopen_s(&fp, wpath.c_str(), L"rt");
    if (fp == nullptr)
    {
        return nullptr;
    }
    fseek(fp, 0, SEEK_END);
    int len = ftell(fp) - 1;
    fseek(fp, 0, SEEK_SET);

    WCHAR bom = 0;
    fread(&bom, sizeof(WCHAR), 1, fp);
    if (bom != 0xFEFF) // UTF-16 Big Endian
    {
        return nullptr;
    }

    int bufCount = len / 2 + 1;
    WCHAR* buf = new WCHAR[bufCount];
    wmemset(buf, 0, bufCount);
    fread(buf, sizeof(WCHAR), bufCount, fp);
    buf[len / 2] = L'\0';

    fclose(fp);

    // parsing
    int width = 0;
    int height = 0;
    int col = 0;
    int line = 1;
    for (int i = 0; i < bufCount; i++)
    {
        if (buf[i] == L'\r')
        {
            if (width == 0)
            {
                width = i;
            }
            line++;
        }
    }

    width = width == 0 ? 1 : width;
    height = line;

    WCHAR* data = new WCHAR[width * height];
    int index = 0;
    for (int i = 0; i < bufCount; i++)
    {
        if (buf[i] == L'\r') continue;
        if (buf[i] == L'\n') continue;
        if (buf[i] == L'\0') continue;
        data[index] = buf[i];
        index++;
    }

    delete[] buf;

    Shape* shape = new Shape();
    shape->buffer = data;
    shape->width = width;
    shape->height = height;

    return shape;
}

Vector2 Shape::GetCenter()
{
    return Vector2(width/2,height/2);
}

int Shape::GetWidth()
{
    return width;
}

int Shape::GetHeight()
{
    return height;
}

WCHAR* Shape::GetBuffer()
{
    return buffer;
}
