#pragma once
#include <vector>
#include <memory>
#include "PostEntity.h"

class PostRepositoryInterface
{
public:
    virtual ~PostRepositoryInterface() = default;
    virtual std::vector<PostEntity> findAll() = 0;
    virtual void save(std::unique_ptr<PostEntity> post) = 0;
    virtual std::vector<PostEntity> findById(int id) = 0;
    virtual void deletePost(int id) = 0;
};
