#include "../../head/clang_enhance.h"

#define vex_num_max 10

typedef struct ArcNode {
    int vertex_index;
    struct ArcNode *nextArc;
} arcItem, *arcPtr;

typedef struct VertexNode {
    char vertex_name;

    // the first arc of pointing to this vertex node
    arcPtr first_arc;

} vertItem, *vertNode;

typedef struct GraphStructor {
    int vertexNums;
    int arcNums;
    vertItem vertexGroup[vex_num_max];
} graphStructor, *graph;

int getPosition(graph g, char ch);

/* ############################################################################################ */

graph initialization_graph(char vertexArr[], int vertexGroupSize, char arcArr[][2], int arcSize) {
    char startNodeName, endNodeName;
    int startNodePosition, endNodePosition;


    graph gph = (graph) malloc(sizeof(graphStructor));

    gph->vertexNums = vertexGroupSize;
    gph->arcNums = arcSize;

    for (int i = 0; i < gph->vertexNums; ++i) {
        gph->vertexGroup[i].vertex_name = vertexArr[i];
        gph->vertexGroup[i].first_arc = NULL;

    }

    for (int i = 0; i < arcSize; ++i) {
        startNodeName = arcArr[i][0];
        endNodeName = arcArr[i][1];

        startNodePosition = getPosition(gph, startNodeName);
        endNodePosition = getPosition(gph, endNodeName);

        arcPtr node = (arcPtr) malloc(sizeof(arcItem));
        node->vertex_index = endNodePosition;
        node->nextArc = NULL;

        if (gph->vertexGroup[startNodePosition].first_arc == NULL) {
            gph->vertexGroup[startNodePosition].first_arc = node;

        } else {

            arcPtr tempNode = gph->vertexGroup[startNodePosition].first_arc;

            while (tempNode->nextArc != NULL) {
                tempNode = tempNode->nextArc;
            }
            tempNode->nextArc = node;

        }
    }
    return gph;
}

int getPosition(graph g, char ch) {
    for (int i = 0; i < g->vertexNums; ++i) {
        if (g->vertexGroup[i].vertex_name == ch) {
            return i;
        }
    }

    return -1;
}

void ergodic_graph(graph g) {
    for (int i = 0; i < g->vertexNums; ++i) {
        arcPtr tempNode = g->vertexGroup[i].first_arc;

        cout << g->vertexGroup[i].vertex_name << "  ";

        while (tempNode) {
            cout << tempNode->vertex_index << "  ";
            cout << g->vertexGroup[tempNode->vertex_index].vertex_name << "  ";

            tempNode = tempNode->nextArc;
        }
        cout << "\n";
    }
}

/**
 * it is a directed graph
 */
void executeGraphTest() {
    char vertex_array[] = {'A', 'B', 'C', 'D', 'E'};
    char arc_array[][2] = {{'A', 'B'},
                           {'A', 'C'},
                           {'A', 'D'},
                           {'B', 'C'},
                           {'B', 'D'},
                           {'C', 'D'},
                           {'D', 'E'}};

    int vertexSize = sizeof(vertex_array) / sizeof(char);
    int arcSize = sizeof(arc_array) / (sizeof(char) * 2);

    graph g = initialization_graph(vertex_array, vertexSize, arc_array, arcSize);
    ergodic_graph(g);
}