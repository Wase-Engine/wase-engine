#pragma once

#include <memory>

#include <ecs.h>

#include <scene/scene_context.h>
#include <rendering/orthographic_camera.h>

namespace wase::scene
{
	class Scene
	{
	public:
		/**
		 * Initialize the scene with a context
		 */
		void initialize(const SceneContext& context);

		/**
		 * Update the ECS systems
		 * 
		 * @param deltaTime The time between frames
		 */
		void updateWorld(const float deltaTime);
		
		/**
		 * Gets called once on the first update
		 */
		virtual void start();

		/**
		 * Gets called every frame
		 */
		virtual void update(const float deltaTime);

	protected:
		Scene();
		Scene(const Scene&) = default;
		Scene& operator=(const Scene&) = delete;
		Scene(Scene&&) = default;
		Scene& operator=(Scene&&) = default;

		SceneContext m_Context;
		ecs::World m_World;
		std::shared_ptr<rendering::OrthographicCamera> m_Camera;
	};
}