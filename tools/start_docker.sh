systemctl restart docker
docker ps 
systemctl status containerd.service 
systemctl stop containerd.service 
systemctl disable containerd.service 
systemctl enable docker 
docker ps -a
docker start b255ccd0c840 

