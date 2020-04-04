set -eu

contest=$1  # e.g., abc001

url="https://atcoder.jp/contests/${contest}/tasks/${contest}"
root_dir=$(pwd)

mkdir -p ${root_dir}/${contest}
if [[ ! -d ${root_dir}/${contest}/${contest}_a ]]; then cp -r ${root_dir}/template ${root_dir}/${contest}/${contest}_a ; fi 
if [[ ! -d ${root_dir}/${contest}/${contest}_b ]]; then cp -r ${root_dir}/template ${root_dir}/${contest}/${contest}_b ; fi 
if [[ ! -d ${root_dir}/${contest}/${contest}_c ]]; then cp -r ${root_dir}/template ${root_dir}/${contest}/${contest}_c ; fi 
if [[ ! -d ${root_dir}/${contest}/${contest}_d ]]; then cp -r ${root_dir}/template ${root_dir}/${contest}/${contest}_d ; fi 
if [[ ! -d ${root_dir}/${contest}/${contest}_e ]]; then cp -r ${root_dir}/template ${root_dir}/${contest}/${contest}_e ; fi 
if [[ ! -d ${root_dir}/${contest}/${contest}_f ]]; then cp -r ${root_dir}/template ${root_dir}/${contest}/${contest}_f ; fi 

cd ${root_dir}/${contest}/${contest}_a && rm -rf test && oj d ${url}_a
cd ${root_dir}/${contest}/${contest}_b && rm -rf test && oj d ${url}_b
cd ${root_dir}/${contest}/${contest}_c && rm -rf test && oj d ${url}_c
cd ${root_dir}/${contest}/${contest}_d && rm -rf test && oj d ${url}_d
cd ${root_dir}/${contest}/${contest}_e && rm -rf test && oj d ${url}_e
cd ${root_dir}/${contest}/${contest}_f && rm -rf test && oj d ${url}_f
