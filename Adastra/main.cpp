#include <iostream>
#include <string>
#include <memory>
#include "PostManager.h"
#include "PostEntity.h"
#include "PostPDO.h"

int main() {
    // Spécifiez le nom du fichier pour stocker les données
    std::string filename = "posts.txt";
    PostPDO postRepository(filename);

    // Créez une instance de PostManager
    PostManager postManager(postRepository);

    // Demandez les détails du post à l'utilisateur
    std::string title;
    double unit_price;
    double wholesale_price;
    int category_id;
    std::string description;

    std::cout << "Title: ";
    std::getline(std::cin, title);

    std::cout << "Unit Price: ";
    std::cin >> unit_price;

    std::cout << "Wholesale Price: ";
    std::cin >> wholesale_price;

    std::cout << "Category ID: ";
    std::cin >> category_id;

    std::cout << "Description: ";
    std::cin.ignore(); // Ignore newline character left in the stream after previous input
    std::getline(std::cin, description);

    // Créez un nouveau PostEntity
    std::unique_ptr<PostEntity> newPost = std::make_unique<PostEntity>(title, unit_price, wholesale_price, category_id, description);

    // Exécutez la méthode pour sauvegarder le post
    std::vector<PostEntity> data = { *newPost };
    postManager.execute(data);

    std::cout << "Post saved successfully." << std::endl;

    return 0;
}
