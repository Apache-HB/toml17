project('toml17', 'cpp',
    default_options : [
        'cpp_std=c++17',
        'cpp_rtti=false',
        'cpp_eh=none'
    ]
)

args = []

if get_option('cpp_rtti')
    args += '-DTOML17_RTTI=1'
endif

if get_option('cpp_eh') != 'none'
    args += '-DTOML17_EXCEPTIONS=1'
endif
