#pragma once

namespace wase::scene
{
	class Scene
	{
	public:
		/**
		 * Gets called once on the first update
		 */
		virtual void start();

		/**
		 * Gets called every frame
		 */
		virtual void update();

	protected:
		Scene() = default;
		Scene(const Scene&) = default;
		Scene& operator=(const Scene&) = delete;
		Scene(Scene&&) = default;
		Scene& operator=(Scene&&) = default;
	};
}