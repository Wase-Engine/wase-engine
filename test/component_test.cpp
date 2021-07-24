#include "../src/wase/core/scene.h"
#include "../src/wase/ecs/entity.h"
#include "../src/wase/ecs/entity_manager.h"
#include "../src/wase/ecs/components/transform.h"

#include <gtest/gtest.h>

namespace wase
{
    TEST(ComponentTest, GetComponent)
    {
        Entity *entity = nullptr;
        Transform *transform = nullptr;

        Scene scene;
        entity = scene.getEntityManager()->addEntity("TestEntity2");
        transform = entity->getComponent<Transform>();
        EXPECT_NE(nullptr, transform);
    }

    TEST(ComponentTest, RemoveComponent)
    {
        Entity *entity = nullptr;
        Scene scene;
        entity = scene.getEntityManager()->addEntity("TestEntity3");
        entity->removeComponent<Transform>();
        EXPECT_FALSE(entity->hasComponent<Transform>());
    }
}