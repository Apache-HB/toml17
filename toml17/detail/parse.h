#pragma once

#include "detail.h"

#include <string>
#include <map>
#include <istream>

namespace toml17::detail
{
    enum class value_type
    {
        floating,
        integer,
        string,
        array,
        object,
        date,
        boolean,
    };

    using value = struct {
        value_type type;
        union {
            double floating;
            std::int_fast64_t integer;
            char* string;

            struct {
                int length;
                value* data;
            };

            struct object* subobject;
        };
    };

    enum class token_type
    {
        key,
        str,
        ident,
        integer,
        floating,
        eof,
    };

    enum class keyword
    {
        openarr, // [
        openarr2, // [[
        closearr, // ]
        closearr2, // ]]
        comma, // ,
        opencurl, // {
        closecurl, // }
        equals, // =
        dot, // .
    };

    struct token
    {
        token() {}
        token(token_type t)
            : type(t)
        {}

        token(keyword k)
            : type(token_type::key)
            , key(k)
        {}

        token(int_fast64_t n)
            : type(token_type::integer)
            , num(n)
        {}

        token_type type;

        union {
            keyword key;
            char* ident;
            char* str;
            int_fast64_t num;
            double flt;
        };
    };

    struct tokenizer
    {
        token next()
        {
            auto temp = tok;
            tok = get();
            return temp;
        }

        token peek()
        {
            return tok;
        }

        tokenizer(std::istream& i)
            : in(i)
        {}

    private:
        token get()
        {
            auto c = in.get();
            using char_type = decltype(c);

            switch(c)
            {
            case std::char_traits<char_type>::eof():
                return token(token_type::eof);

            case '[':
                if(in.peek() == '[')
                {
                    in.get();
                    return token(keyword::openarr2);
                }
                return token(keyword::openarr);

            case ']':
                if(in.peek() == ']')
                {
                    in.get();
                    return token(keyword::closearr2);
                }
                return token(keyword::closearr);

            case '.':
                return token(keyword::dot);
            case '=':
                return token(keyword::equals);
            case ',':
                return token(keyword::comma);
            case '{':
                return token(keyword::opencurl);
            case '}':
                return token(keyword::closecurl);

                // literal string
            case '\'':

                // multiline string literal
                if(c = in.get(); c == '\'' && in.peek() == '\'')
                {

                }

                // basic string
            case '"':

                // multiline basic string
                if(c = in.get(); c == '"' && in.peek() == '"')
                {

                }

            default:
                return parse_other(c);
            }
        }

        token parse_other(int c)
        {
            if(c == '0')
            {
                switch(in.peek())
                {
                case 'x': case 'X': break;
                    in.get();
                    return token(parse_hex());
                case 'o': case 'O': break;
                    in.get();
                    return token(parse_octal());
                case 'b': case 'B': break;
                    in.get();
                    return token(parse_binary());
                default: 
                    return token(parse_integer();)
                break;
                }
            }
            else if(std::isdigit(c))
            {

            }
            else if(c == '+')
            {

            }
            else if(c == '-')
            {

            }
            else if(std::isalnum(c))
            {

            }
        }

        int_fast64_t parse_hex()
        {

        }

        int_fast64_t parse_octal()
        {

        }

        int_fast64_t parse_binary() 
        {

        }

        int_fast64_t parse_integer()
        {

        }

        std::istream& in;
        token tok;
    };

    std::map<std::string, value> parse(std::istream& input)
    {
        
        return {};
    }
}