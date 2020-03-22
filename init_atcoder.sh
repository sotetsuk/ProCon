set -eu

contest=$1  # e.g., abc001

url="https://atcoder.jp/contests/${contest}/tasks/${contest}"
root_dir=$(pwd)

mkdir -p ${root_dir}/${contest}
if [[ ! -d ${root_dir}/${contest}/a ]]; then cp -r ${root_dir}/template ${root_dir}/${contest}/a ; fi 
if [[ ! -d ${root_dir}/${contest}/b ]]; then cp -r ${root_dir}/template ${root_dir}/${contest}/b ; fi 
if [[ ! -d ${root_dir}/${contest}/c ]]; then cp -r ${root_dir}/template ${root_dir}/${contest}/c ; fi 
if [[ ! -d ${root_dir}/${contest}/d ]]; then cp -r ${root_dir}/template ${root_dir}/${contest}/d ; fi 
if [[ ! -d ${root_dir}/${contest}/e ]]; then cp -r ${root_dir}/template ${root_dir}/${contest}/e ; fi 
if [[ ! -d ${root_dir}/${contest}/f ]]; then cp -r ${root_dir}/template ${root_dir}/${contest}/f ; fi 

cd ${root_dir}/${contest}/a && rm -rf test && oj d ${url}_a
cd ${root_dir}/${contest}/b && rm -rf test && oj d ${url}_b
cd ${root_dir}/${contest}/c && rm -rf test && oj d ${url}_c
cd ${root_dir}/${contest}/d && rm -rf test && oj d ${url}_d
cd ${root_dir}/${contest}/e && rm -rf test && oj d ${url}_e
cd ${root_dir}/${contest}/f && rm -rf test && oj d ${url}_f
