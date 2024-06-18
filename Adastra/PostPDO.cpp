#include "PostPDO.h"

static int nextId = 1;

PostPDO::PostPDO(const std::string& filename)
    : m_filename(filename)
{
}

PostPDO::~PostPDO()
{
}

std::vector<PostEntity> PostPDO::findAll()
{
    return readFromFile();
}

void PostPDO::save(std::unique_ptr<PostEntity> post)
{
    post->setId(nextId++);
    writeToFile(*post);
}

std::vector<PostEntity> PostPDO::findById(int id)
{
    std::vector<PostEntity> allPosts = readFromFile();
    std::vector<PostEntity> result;

    for (const auto& post : allPosts) {
        if (post.getId() == id) {
            result.push_back(post);
        }
    }
    return result;
}

void PostPDO::deletePost(int id)
{
    std::vector<PostEntity> allPosts = readFromFile();
    std::ofstream outFile(m_filename, std::ios::trunc);

    for (const auto& post : allPosts) {
        if (post.getId() != id) {
            outFile << post.serialize() << std::endl;
        }
    }
    outFile.close();
}

void PostPDO::writeToFile(const PostEntity& post)
{
    std::ofstream outFile(m_filename, std::ios::app);
    if (outFile.is_open()) {
        outFile << post.serialize() << std::endl;
        outFile.close();
    }
}

std::vector<PostEntity> PostPDO::readFromFile()
{
    std::vector<PostEntity> posts;
    std::ifstream inFile(m_filename);
    std::string line;

    while (std::getline(inFile, line)) {
        posts.push_back(PostEntity::deserialize(line));
    }
    inFile.close();
    return posts;
}
