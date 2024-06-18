#pragma once
#include <string>
#include <iostream>
#include <sstream>

class PostEntity {
private:
    int id;
    std::string m_title;
    double m_unit_price;
    double m_wholesale_price;
    int m_category_id;
    std::string m_description;
public:
    PostEntity(std::string title = "", double unit_price = 0.0, double wholesale_price = 0.0, int category_id = 1, std::string description = "")
        : m_title(title), m_unit_price(unit_price), m_wholesale_price(wholesale_price), m_category_id(category_id), m_description(description), id(0) {}

    ~PostEntity() {}

    int getId() const { return id; }
    void setId(int id) { id = id; }
    std::string getTitle() const { return m_title; }
    void setTitle(const std::string& title) { m_title = title; }

    double getUnitPrice() const { return m_unit_price; }
    void setUnitPrice(double unit_price) { m_unit_price = unit_price; }

    double getWholesalePrice() const { return m_wholesale_price; }
    void setWholesalePrice(double wholesale_price) { m_wholesale_price = wholesale_price; }

    int getCategoryId() const { return m_category_id; }
    void setCategoryId(int category_id) { m_category_id = category_id; }

    std::string getDescription() const { return m_description; }
    void setDescription(const std::string& description) { m_description = description; }

    std::string serialize() const {
        std::ostringstream oss;
        oss << id << "," << m_title << "," << m_unit_price << "," << m_wholesale_price << "," << m_category_id << "," << m_description;
        return oss.str();
    }

    static PostEntity deserialize(const std::string& data) {
        std::istringstream iss(data);
        std::string token;

        std::getline(iss, token, ',');
        int id = std::stoi(token);

        std::getline(iss, token, ',');
        std::string title = token;

        std::getline(iss, token, ',');
        double unit_price = std::stod(token);

        std::getline(iss, token, ',');
        double wholesale_price = std::stod(token);

        std::getline(iss, token, ',');
        int category_id = std::stoi(token);

        std::getline(iss, token, ',');
        std::string description = token;

        return PostEntity(title, unit_price, wholesale_price, category_id, description);
    }
};
