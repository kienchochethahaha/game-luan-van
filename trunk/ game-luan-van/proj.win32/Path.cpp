#include "Path.h"

Path ::Path()
{
	nodes = new std::vector<CCPoint>();
	m_radiusPath = 30;
}
void Path ::addNode (CCPoint node)
{
	nodes->push_back(node);

}