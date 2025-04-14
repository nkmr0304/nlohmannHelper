/*
 *	@File	JsonHelper.h
 *	@Brief	jsonファイルのヘルパークラス。
 *	@Date	2023-01-18
 *  @Author NakamuraRyo
 */

// jsonライブラリのインクルード
#include "json.hpp"
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
////   Json for Modern C++                                   ////
////   Version 3.11.2                                        ////
////   Author Niels Lohmann                                  ////
////   DownLoad for URL : https://github.com/nlohmann/json   ////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

#pragma once
#ifndef JSONHELPER
#define JSONHELPER

// エイリアス宣言
using Json = nlohmann::json;

class JsonHelper
{
public:
	JsonHelper();
	~JsonHelper();
	// 読み込み
	bool Load(const wchar_t* path);
	// 書き込み
	bool Write(std::string str);
	// データの取得
	Json GetData() { return m_json; }
	// パスの設定
	void SetPath(const wchar_t* path) { m_path = path; }

private:

	Json m_json;
	std::wstring m_path;
};

#endif // JSONHELPER