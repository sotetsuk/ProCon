set -eu

contest=$1  # e.g., abc001

url="https://atcoder.jp/contests/${contest}/tasks/${contest}"
root_dir=$(pwd)

cd ${root_dir}/${contest}/${contest}_a && rm -rf test && oj d ${url}_a
cd ${root_dir}/${contest}/${contest}_b && rm -rf test && oj d ${url}_b
cd ${root_dir}/${contest}/${contest}_c && rm -rf test && oj d ${url}_c
cd ${root_dir}/${contest}/${contest}_d && rm -rf test && oj d ${url}_d
cd ${root_dir}/${contest}/${contest}_e && rm -rf test && oj d ${url}_e
cd ${root_dir}/${contest}/${contest}_f && rm -rf test && oj d ${url}_f
