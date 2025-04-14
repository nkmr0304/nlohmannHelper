/*
 *	@File	JsonHelper.cpp
 *	@Brief	jsonファイルのヘルパークラス。
 *	@Date	2023-01-18
 *  @Author NakamuraRyo
 */

#include "pch.h"
#include <iostream>
#include <fstream>
#include "JsonHelper.h"

JsonHelper::JsonHelper() // コンストラクタ
	: m_json{}
	, m_path{}
{
}
JsonHelper::~JsonHelper() // デストラクタ
{
	m_json.clear();
	m_path.clear();
}
bool JsonHelper::Load(const wchar_t* path) // 読み込み
{
	// Jsonファイルの読み込み
	std::ifstream ifs(path, std::ios::in);

	if (!ifs) return EXIT_FAILURE;

	// Jsonデータの取り出し
	ifs >> m_json;

	// Jsonファイルを閉じる
	ifs.close();

	// パスを保存して正常終了
	m_path = path;
	return EXIT_SUCCESS;
}
bool JsonHelper::Write(std::string str) // 書き出し
{
	// Jsonファイルの書き込み
	std::ofstream ofs(m_path, std::ios::out);

	if (!ofs) return EXIT_FAILURE;

	// Jsonデータの書き出し
	ofs << str;

	// Jsonファイルを閉じる
	ofs.close();

	return EXIT_SUCCESS;
}
