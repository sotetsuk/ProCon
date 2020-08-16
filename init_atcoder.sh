set -eu

contest=$1  # e.g., abc001
root_dir=$(pwd)

mkdir -p ${root_dir}/${contest}
if [[ ! -d ${root_dir}/${contest}/${contest}_a ]]; then cp -r ${root_dir}/template ${root_dir}/${contest}/${contest}_a ; fi 
if [[ ! -d ${root_dir}/${contest}/${contest}_b ]]; then cp -r ${root_dir}/template ${root_dir}/${contest}/${contest}_b ; fi 
if [[ ! -d ${root_dir}/${contest}/${contest}_c ]]; then cp -r ${root_dir}/template ${root_dir}/${contest}/${contest}_c ; fi 
if [[ ! -d ${root_dir}/${contest}/${contest}_d ]]; then cp -r ${root_dir}/template ${root_dir}/${contest}/${contest}_d ; fi 
if [[ ! -d ${root_dir}/${contest}/${contest}_e ]]; then cp -r ${root_dir}/template ${root_dir}/${contest}/${contest}_e ; fi 
if [[ ! -d ${root_dir}/${contest}/${contest}_f ]]; then cp -r ${root_dir}/template ${root_dir}/${contest}/${contest}_f ; fi 
