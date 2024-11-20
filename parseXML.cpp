#include <iostream>
#include <libxml/parser.h>
#include <libxml/tree.h>

void parseXML(const char *filename)
{
    xmlDocPtr doc;
    xmlNodePtr root, node;

    // Parse the XML file
    doc = xmlParseFile(filename);
    if (doc == NULL)
    {
        std::cerr << "Error: Could not parse the XML file!" << std::endl;
        return;
    }

    root = xmlDocGetRootElement(doc);
    node = root->children;

    // Loop through XML nodes
    while (node)
    {
        if (node->type == XML_ELEMENT_NODE && xmlStrEqual(node->name, BAD_CAST "book"))
        {
            xmlNodePtr titleNode = node->children;
            while (titleNode)
            {
                if (titleNode->type == XML_ELEMENT_NODE && xmlStrEqual(titleNode->name, BAD_CAST "title"))
                {
                    std::cout << "Book Title: " << xmlNodeGetContent(titleNode) << std::endl;
                }
                titleNode = titleNode->next;
            }
        }
        node = node->next;
    }

    // Free the document
    xmlFreeDoc(doc);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << "catalog.xml" << std::endl;
        return 1;
    }

    parseXML(argv[1]);

    return 0;
}
