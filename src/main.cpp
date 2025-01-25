#include "Poco/AutoPtr.h"
#include "Poco/DOM/Text.h"
#include "Poco/DOM/Element.h"
#include "Poco/DOM/Comment.h"
#include "Poco/DOM/ProcessingInstruction.h"
#include "Poco/DOM/Attr.h"
#include "Poco/DOM/Document.h"
#include "Poco/DOM/DOMWriter.h"
#include "Poco/DOM/text.h"
#include "Poco/DOM/CDATASection.h"
#include "Poco/DOM/DOMParser.h"
#include "Poco/DOM/Node.h"
#include "Poco/DOM/NamedNodeMap.h"
#include "Poco/XML/XMLString.h"
#include "Poco/XML/XMLException.h"
#include "Poco/XML/XMLStream.h"
#include "Poco/DOM/NodeIterator.h"
#include "Poco/DOM/NodeFilter.h"
#include "Poco/String.h"
#include "Poco/RegularExpression.h"

#include <iostream>

void trim(std::string& str)
{
    //For Poco string function list. see: https://blog.csdn.net/u010168781/article/details/134983856
    Poco::trimInPlace(str);
    return;
}

void trim(std::wstring& wstr)
{
    Poco::trimInPlace(wstr);
    return;
}

void regtest()
{
    Poco::RegularExpression rel("[0-9]+");
    std::string str = "123";
    bool match = rel.match(str);
    std::cout << str << "->result:" << rel.match(str) << std::endl;
    str = "abc";
    match = rel.match(str);
    std::cout << str << "->result:" << rel.match(str) << std::endl;
}

void read_xml()
{
//    std::cout << "Run at: " << __LINE__ << std::endl;

    Poco::XML::DOMParser parser;
    Poco::AutoPtr<Poco::XML::Document> doc = parser.parse("c:\\test\\test.xml");
    Poco::XML::NodeIterator it(doc, Poco::XML::NodeFilter::SHOW_ALL);
    Poco::XML::Node* node = it.nextNode();
    


    int i = 0;
    while (node)
    {

     /*   if (node->nodeType() != Poco::XML::Node::ELEMENT_NODE)
        {
            node = it.nextNode();
            continue;
        }
        if (node->nodeName() == "#text")
        {
            std::cout << "#text:" << i << ":" << node->nodeName() << ":" << node->nodeValue() << std::endl;

            node = it.nextNode();
            continue;
        }
       if (node->nodeName() == "#cdata-section")
        {
            std::cout << "#cdata-section :" << i << ": name:" << node->nodeName() << " :value: " << node->nodeValue() << " :innerText: " << node->innerText() << std::endl;
            node = it.nextNode();
            continue;
        }*/

        std::cout << "nodeType:" << node->nodeType() << ". nodename:" << node->nodeName() << " :nodevalue: " << node->nodeValue() << " :nodeinnerText: " << node->innerText() << std::endl;

        Poco::XML::NamedNodeMap* map = node->attributes();
        if (map)
        {
            for (size_t i = 0; i < map->length(); ++i)
            {
                Poco::XML::Node* c = map->item(i);
                std::string n1 = c->nodeName();
                std::string v1 = c->nodeValue();
                std::cout << "attributes:" << n1 << ":" << v1 << std::endl;
            }
        }
        node = it.nextNode();
    }
}
int main(int argc, char** argv)
{
    std::cout << "Run start." << std::endl;
    read_xml();
    std::string str = "   hello world!   ";
    trim(str);
    regtest();
    std::cout << "str:" << str <<"." << std::endl;
    std::cout << "Run OK." << std::endl;
    return 0;
}