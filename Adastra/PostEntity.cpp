#include "PostEntity.h"

std::ostream& operator<<(std::ostream& os, const PostEntity& post) {
    os << "Title: " << post.getTitle() << "\n"
        << "Unit Price: " << post.getUnitPrice() << "\n"
        << "Wholesale Price: " << post.getWholesalePrice() << "\n"
        << "Category ID: " << post.getCategoryId() << "\n"
        << "Description: " << post.getDescription() << "\n";
    return os;
}
