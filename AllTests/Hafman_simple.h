#pragma once

#include <vector>
#include <map>
#include <memory>

struct map_hafman
{
    char val_{ 0 };
    int  freq_{ 0 };
    std::shared_ptr<map_hafman> right_{ nullptr };
    std::shared_ptr<map_hafman> left_{ nullptr };
    std::shared_ptr<map_hafman> parent_{ nullptr };
    bool visited{ false };
    map_hafman() {}
    map_hafman(
        char val,
        int freq,
        std::shared_ptr<map_hafman> right = nullptr,
        std::shared_ptr<map_hafman> left = nullptr,
        std::shared_ptr<map_hafman> parent = nullptr)
        : val_(val)
        , freq_(freq)
        , right_(right)
        , left_(left)
        , parent_(parent)
    {}
};

std::pair<char, std::shared_ptr<map_hafman>> extract_min(std::multimap<char, std::shared_ptr<map_hafman>>& hafman_codes)
{  
    auto start_it = hafman_codes.begin();
    auto end_it   = hafman_codes.end();
    std::pair<char, std::shared_ptr<map_hafman>> pair;
    if (start_it == end_it)
        return pair = std::make_pair<char, std::shared_ptr<map_hafman>>(0, nullptr);

    int min = hafman_codes.begin()->second->freq_;

    std::map<char, std::shared_ptr<map_hafman>>::iterator it_last = start_it;
    for (auto it = start_it; it != end_it; ++it)
    {
        if (it->second->freq_ < min)
        {
            min = it->second->freq_;
            it_last = it;
        }
    }
    if (it_last != end_it)
    {
        pair = std::make_pair(it_last->first, it_last->second);
        hafman_codes.erase(it_last);
    }
    return pair;
}

void postorderNonRecursive(std::shared_ptr<map_hafman> root, std::map<char, std::string>& codes) {
    std::shared_ptr<map_hafman> current = root;
    std::string code = "";
    while (current) {
        if (current->left_ && !current->left_->visited) {
            current = current->left_;
            code.append("0");
            continue;
        }
        else if (current->right_ && !current->right_->visited) {
            current = current->right_;
            code.append("1");
            continue;
        }

        if (!current->visited) {
            if (current->val_ != 0)
            {
                codes[current->val_] = code;
            }
            current->visited = true;
        }

        if (current->left_)
            current->left_->visited = false;
        if (current->right_)
            current->right_->visited = false;

        code = code.substr(0, code.length()-1);

        current = current->parent_;
    };
    if (root)
        root->visited = false;
}


std::map<char, std::string> hafman_encode(std::string& str_to_code)
{
    std::multimap<char, std::shared_ptr<map_hafman>> hafman_codes;
    std::map<char, std::string> hafman_codes_res;
    std::shared_ptr<map_hafman> root(new map_hafman);
    for (char charter : str_to_code)
    {
        auto const_it = hafman_codes.find(charter);
        if (const_it != hafman_codes.end())
            const_it->second->freq_ += 1;
        else
            hafman_codes.emplace(charter, new map_hafman(charter, 1));
    }
    auto hafman_codes_copy = hafman_codes;
    while(!hafman_codes.empty())
    {  
        auto min_first  = extract_min(hafman_codes);
        auto min_second = extract_min(hafman_codes);
        if (min_first.second->freq_ < min_second.second->freq_)
            std::swap(min_first, min_second);
        if (min_first.first == '0')
            std::swap(min_first, min_second);
        
        int parent_val = min_second.second->freq_ + min_first.second->freq_;
        std::shared_ptr<map_hafman> new_parent(
            new map_hafman(0, 
                           parent_val,    
                           min_second.second,
                           min_first.second,
                           root
            )
        );
        new_parent->right_->parent_ = new_parent;
        new_parent->left_->parent_ = new_parent;
        root = new_parent;

        if (!hafman_codes.empty())
            hafman_codes.emplace(new_parent->val_, new_parent);
    }
    root->parent_ = nullptr;

    postorderNonRecursive(root, hafman_codes_res);
    return hafman_codes_res;
}

/* Main example
std::string hafman_str;
std::cin >> hafman_str;
auto ptr = hafman_simple(hafman_str);

std::string output_str;
for (auto ch : hafman_str)
{
std::string new_ch = ptr.find(ch)->second;
output_str.append(new_ch);
}
std::cout << ptr.size() << " " << output_str.length() << std::endl;
for (auto elem : ptr)
{
std::cout << elem.first << ": " << elem.second << std::endl;
}
std::cout << output_str << std::endl;
*/

std::string hafman_decode(std::string str_to_code, std::map<std::string, std::string> letters)
{
    std::string res_output = "";
    std::string part_of_code = "";
    
    for (char charter : str_to_code)
    {
        part_of_code.append(std::string(1, charter));
        if (letters.find(part_of_code) != letters.end())
        {
            res_output.append(letters[part_of_code]);
            part_of_code.clear();
        }
    }

    return res_output;
}

//std::string str_to_code = "";
//std::map<std::string, std::string> letters;
//
//int variants = 0;
//int length_str = 0;
//
//std::cin >> variants;
//std::cin >> length_str;
//variants;
//std::string letter;
//std::string code;
//while (variants)
//{
//    std::cin >> letter;
//    letter = letter.substr(0, letter.length() - 1);
//    std::cin >> code;
//    letters.emplace(code, letter);
//    --variants;
//}
//std::cin >> str_to_code;
//
//std::string res = hafman_decode(str_to_code, letters);
//std::cout << res << std::endl;