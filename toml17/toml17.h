#pragma once

#include "detail/wrapfs.h"
#include "detail/parse.h"

namespace toml17
{

    struct object
    {
        bool has(const std::string& key) const;
        
        template<typename T>
        T get(const std::string& key) const;

        template<typename T>
        T get_or(const std::string& key, T other) const;
 
        template<typename T>
        void set(const std::string& key, T val);

    private:
        std::map<std::string, value> values;
    };

    object parse(const fs::path& path)
    {

    }

    object load(const std::string& str)
    {

    }

    std::string write(const object& obj)
    {

    }
    
    void save(const fs::path& path, const object& obj)
    {

    }
}