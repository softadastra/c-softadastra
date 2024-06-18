#include "PostManager.h"
#include <iostream>

PostManager::PostManager(PostRepositoryInterface& repo)
    : repository(repo)
{
    std::cout << "Created PostManager" << std::endl;
}

PostManager::~PostManager()
{
    std::cout << "Destroyed PostManager" << std::endl;
}

void PostManager::execute(std::vector<PostEntity> data)
{
    std::unique_ptr<PostEntity> post = std::make_unique<PostEntity>();
    this->repository.save(std::move(post));
}
