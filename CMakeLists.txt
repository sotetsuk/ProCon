# ref. https://qiita.com/nokaruku/items/2cb98f6276d81c0303a2

cmake_minimum_required(VERSION 3.14)
project(procon)

set(CMAKE_CXX_STANDARD 14)

# Use boost (ref. https://stackoverflow.com/questions/3808775/cmake-doesnt-find-boost)
find_package(Boost)
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()

# 指定したとこ含めて、cppファイルがあったらビルド構成作る
MACRO(CREATE_BINARY target_dir)
    # 指定したディレクトリの中身一覧（孫までは取れない）
    FILE(GLOB children RELATIVE ${target_dir} ${target_dir}/*)
    FOREACH(child ${children})
        SET(path ${target_dir}/${child})
        # ディレクトリなら更に潜る、生成されるディレクトリは除外
        IF(IS_DIRECTORY ${path} AND NOT ${path} MATCHES "cmake-build-debug")
            CREATE_BINARY(${path})
        # cppファイルならバイナリー作成
        ELSEIF(${path} MATCHES \.cpp$)
            # バイナリー名を用意
            SET(binary_name "")
            STRING(REGEX MATCH [^\/]+\/[^\/]+\.cpp$ binary_name ${path})
            STRING(REGEX REPLACE "\/" "_" binary_name ${binary_name})
            STRING(REGEX REPLACE "\.cpp" "" binary_name ${binary_name})
            # 実行可能ファイルを追加
            ADD_EXECUTABLE(${binary_name} ${path})
        ENDIF()
    ENDFOREACH()
ENDMACRO()

CREATE_BINARY(${CMAKE_CURRENT_SOURCE_DIR})
