#pragma once
#include "PostRepositoryInterface.h"
#include <vector>
#include "PostEntity.h"

class PostManager
{
public:
    PostRepositoryInterface& repository;

    PostManager(PostRepositoryInterface& repo);
    ~PostManager();
    void execute(std::vector<PostEntity> data);
};
