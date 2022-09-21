#pragma once

namespace wase
{
	class Engine
	{
	public:
		~Engine() = default;
		Engine(const Engine&) = delete;
		Engine& operator=(const Engine&) = delete;
		Engine(Engine&&) = default;
		Engine& operator=(Engine&&) = default;

		/**
		 * Get the instance of the engine.
		 */
		static Engine& get();

		/**
		 * Initialize the engine.
		 */
		void initialize();

		/**
		 * Shut down the engine and all running processes
		 */
		void shutdown();

	private:		
		Engine() = default;
	};
}