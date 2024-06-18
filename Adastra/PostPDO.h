#pragma once
#include "PostRepositoryInterface.h"
#include <fstream>
#include <vector>
#include <iostream>

class PostPDO : public PostRepositoryInterface
{
public:
    PostPDO(const std::string& filename);
    ~PostPDO();
    std::vector<PostEntity> findAll() override;
    void save(std::unique_ptr<PostEntity> post) override;
    std::vector<PostEntity> findById(int id) override;
    void deletePost(int id) override;

private:
    std::string m_filename;
    void writeToFile(const PostEntity& post);
    std::vector<PostEntity> readFromFile();
};
