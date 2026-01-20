#!/bin/bash
set -e

# 获取当前文件所在路径的绝对路径
get_cur_abs_path()
{
	local old_path=$(pwd)
	echo "$(cd `dirname $0`; pwd)"
	cd $old_path
}

# 全局变量，表示当前脚本所在绝对路径
cur_abs_path=$(get_cur_abs_path)

cmake -S ${cur_abs_path} \
	-B ${cur_abs_path}/build \
	-DCMAKE_BUILD_TYPE=Debug \
	-DCMAKE_SOURCE_DIR=${cur_abs_path}
cmake --build ${cur_abs_path}/build