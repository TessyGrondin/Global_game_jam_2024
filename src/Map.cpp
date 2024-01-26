#include "include/Map.hpp"

Map::Map(unsigned int tilesize, unsigned int height, unsigned int width)
{
    m_square = tilesize;
    m_height = height;
    m_width = width;
}

bool Map::add_layer(std::string name, std::string path, std::string asset_path)
{
    LayerMap layer(name, m_height, m_width, m_square);
    if (!layer.load(path, asset_path))
        return false;
    m_layers.push_back(layer);
    return true;
}
