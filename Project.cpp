#include <iostream>

//tinyurl.com/899t5ank

using std::cin;
using std::cout;
using std::endl;

class Tree;
class TreeIterator;

class Node
{
    Node* left,
        * right,
        * parent;

    friend class Tree;

public:
    Node* getLeft  () { return left  ; }
    Node* getRight () { return right ; }
    Node* getParent() { return parent; }


    Node* findMin() //возвращает минимальный элемент из текущего поддерева
    {
        auto  node = this;
        while(node->left)
        {
            node = node->left;
        }

        return node;
    }
    Node* findMax() //возвращает максимальный элемент из текущего поддерева
    {
        auto  node = this;
        while(node->right)
        {
            node = node->right;
        }

        return node;
    }


    const Node* getLeft  () const { return left  ; }
    const Node* getRight () const { return right ; }
    const Node* getParent() const { return parent; }

    std::string name;
    std::string description;

    Node(const std::string& name_,
                    Node*   parent_ = nullptr) :
                            left   (  nullptr ),
                            right  (  nullptr ),
                            parent (  parent_ ),
                            name   (  name_   ) { }
};

class Tree
{
    Node* root;

public:
          Node* getRoot()       { return root; }
    const Node* getRoot() const { return root; }

    Tree() : root(nullptr) { }

    Node* addNode ( const std::string& name ) //добавление узла
    {
        Node* closest = findClosest(name);
        if (closest && closest->name == name)
            return nullptr;

        Node* newNode = new Node(name, closest);

        /// TODO: настроить left/right, а также parent у получаемых детей

        return newNode;
    }
    Node* findNode( const std::string& name)
    {
        for (auto node = root; node;)
        {
            auto res = name.compare(node->name);

            if (res == 0)
                return node;
            if (res < 0)
                node = node->left;
            else
                node = node->right;
        }
        return nullptr;
    }

    Node* findMin()
    {
        Node* node = root;
        if ( !node)
            return nullptr;
        while(node->left)
            node = node->left;
        return node;
    }

    Node* findMax()
    {
        Node* node = root;
        if ( !node)
            return nullptr;
        while(node->right)
            node = node->right;
        return node;
    }

    /// Ищет узел с таким же, или максимально близким справа ("большим") значением name.
    Node* findClosest(const std::string& name)
    {
        Node* node = root;
        while(!node)
          if (std::stoi(name) <= std::stoi(node->name))
            return node;
          if (node)
            node = node->right;
    }

    void deleteNode(Node* node)
    {

    }

    TreeIterator begin() {}    /// Возвращает итератор, указывающий на минимальный элемент
    TreeIterator end()   {}       /// Возвращает итератор, указывающий на nullptr Node
};

class TreeIterator : public std::iterator<std::input_iterator_tag, Node>
{
    Node* node;

public:
    TreeIterator()            : node(nullptr) {}
    TreeIterator(Node* node_) : node(node_  ) {}

    bool operator == (const TreeIterator& other) const { return node == other.node; }
    bool operator != (const TreeIterator& other) const { return node != other.node; }

          Node& operator * ()       { return *node; }
    const Node& operator * () const { return *node; }

    TreeIterator& operator++()
    {
      /// 1. Если есть элемент справа, берём его.
        /// 2. Иначе, поднимаемся наверх:
        /// 2.1. Если мы уже наверху, то проход закончен (node выставляем в nullptr).
        /// 2.2. Если мы были в левом поддереве, то возвращаем правый элемент текущего родителя
        /// 2.3. Иначе, переходим на шаг 2.


        if (node->getRight())
        {
            node = node->getRight();
        }
        else
        {
            if (node->getParent())
                node = node->getParent();
            else
                node = nullptr;
        }

        return *this;
    }
    TreeIterator  operator++(int)
    {
        TreeIterator old(node);
        ++* this;
        return old;
    }
    TreeIterator& operator--()
    {

    }
    TreeIterator  operator--(int)
    {
        TreeIterator old(node);
        --* this;
        return old;
    }
};

/// TreeIterator it;
/// it++     ++it


#include <map>
#include <set>

int main()
{
    Tree tree;
    //tree.addNode("First");
    //tree.addNode("Second");
    // tree.addNode("Third");
    std::cout << "Our tree:" << std::endl;
    for (auto& node : tree) {
        std::cout << node.name << ": " << node.description << std::endl;
    }

    std::set<std::string> setOfStrings;
    std::map<std::string, std::string> myMap;

    setOfStrings.insert("First");
    setOfStrings.insert("Second");
    setOfStrings.insert("Third");
    setOfStrings.insert("First");
    setOfStrings.insert("First");
    std::cout << "Set contains:" << std::endl;
    for (auto s : setOfStrings)
        std::cout << s << std::endl;
    std::cout << std::endl;

    myMap["First"] = "La-la-la";
    myMap["Second"] = "La-la-la";
    myMap["Third"] = "La-la-la";
    myMap["First"] = "Fa-fa-fa";
    std::cout << "Map contains:" << std::endl;
    for (auto s : myMap)    /// std::pair<std::string, std::string>
        std::cout << s.first << " -> " << s.second << std::endl;
    std::cout << std::endl;


    return 0;
}
