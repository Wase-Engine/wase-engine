#pragma once

#include <spdlog/spdlog.h>

#ifdef WASE_DEBUG
#define WASE_CORE_TRACE(...) ::wase::debugging::LogManager::getCoreLogger()->trace(__VA_ARGS__)
#define WASE_CORE_INFO(...) ::wase::debugging::LogManager::getCoreLogger()->info(__VA_ARGS__)
#define WASE_CORE_WARN(...) ::wase::debugging::LogManager::getCoreLogger()->warn(__VA_ARGS__)
#define WASE_CORE_ERROR(...) ::wase::debugging::LogManager::getCoreLogger()->error(__VA_ARGS__)
#define WASE_CORE_CRITICAL(...) ::wase::debugging::LogManager::getCoreLogger()->critical(__VA_ARGS__)
#else
#define WASE_CORE_TRACE(...) (void)0
#define WASE_CORE_INFO(...) (void)0
#define WASE_CORE_WARN(...) (void)0
#define WASE_CORE_ERROR(...) (void)0
#define WASE_CORE_CRITICAL(...) (void)0
#endif