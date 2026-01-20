#!/bin/bash
set -e

# get the absolute path of the current script
get_cur_abs_path()
{
	local old_path=$(pwd)
	echo "$(cd `dirname $0`; pwd)"
	cd $old_path
}

# global variable, represents the absolute path of the current script
cur_abs_path=$(get_cur_abs_path)

cmake -S ${cur_abs_path} \
	-B ${cur_abs_path}/build \
	-DCMAKE_BUILD_TYPE=Debug \
	-DCMAKE_SOURCE_DIR=${cur_abs_path}
cmake --build ${cur_abs_path}/build