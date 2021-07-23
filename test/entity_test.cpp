#include "../src/wase/core/scene.h"
#include "../src/wase/ecs/entity.h"
#include "../src/wase/ecs/entity_manager.h"

#include <gtest/gtest.h>

namespace wase
{
    TEST(EntityTest, AddEntity)
    {
        Entity *entity = nullptr;
        Entity *entity2 = nullptr;

        Scene scene;
        entity = scene.getEntityManager()->addEntity("TestEntity1");
        entity2 = scene.getEntityManager()->getEntity("TestEntity1");
        EXPECT_NE(nullptr, entity2);
    }
}