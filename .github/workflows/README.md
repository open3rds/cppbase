## install [act](https://github.com/nektos/act) locally
- make sure docker is installed.
- run this: `curl https://raw.githubusercontent.com/nektos/act/master/install.sh | sudo bash`
- execute `export PATH=$PATH:${install_path}` in shell
- run `act -l` to see job list.
- run `act -j ${job_name}` to run a job.