FROM ros:humble-perception

RUN apt-get update && apt-get install -y gedit
RUN echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
