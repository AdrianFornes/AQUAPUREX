#!/usr/bin/env python

import rospy
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from turtlesim.srv import Kill, Spawn
from math import radians

class MoveTurtle:
    def _init_(self):
        rospy.init_node('move_turtle')
        
        # Suscribirse al topic de la posición de la tortuga
        self.pose_subscriber = rospy.Subscriber('/turtle1/pose', Pose, self.pose_callback)
        
        # Publicar en el topic de comandos de movimiento de la tortuga
        self.velocity_publisher = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size=10)
        
        # Variables para la posición actual de la tortuga
        self.current_x = 0
        self.current_y = 0

    def pose_callback(self, pose):
        # Función que se ejecuta cada vez que llega una actualización de la posición de la tortuga
        self.current_x = pose.x
        self.current_y = pose.y

    def move_forward(self, distance):
        # Crear un mensaje de Twist para avanzar
        move_msg = Twist()
        move_msg.linear.x = distance
        self.velocity_publisher.publish(move_msg)

    def rotate(self, angle):
        # Crear un mensaje de Twist para rotar
        rotate_msg = Twist()
        rotate_msg.angular.z = angle
        self.velocity_publisher.publish(rotate_msg)

    def kill_turtle(self):
        # Llamar al servicio de eliminación de tortugas
        rospy.wait_for_service('/kill')
        try:
            kill_turtle = rospy.ServiceProxy('/kill', Kill)
            kill_turtle("turtle1")
        except rospy.ServiceException as e:
            print("Error al eliminar la tortuga: %s" % e)

    def spawn_turtle(self):
        # Llamar al servicio de spawneado de tortugas
        rospy.wait_for_service('/spawn')
        try:
            spawn_turtle = rospy.ServiceProxy('/spawn', Spawn)
            spawn_turtle(6.7, 3.5, 0, "turtle1")
        except rospy.ServiceException as e:
            print("Error al spawneado de la tortuga: %s" % e)

    def move_turtle(self):
        # Eliminar la tortuga actual
        self.kill_turtle()

        # Spawnear una nueva tortuga en la posición especificada
        self.spawn_turtle()

        # Mover la tortuga a una posición específica
        self.move_forward(1)  # Mover 2 unidades hacia adelante
        rospy.sleep(1)        # Esperar un segundo
        self.rotate(radians(0))  # Girar 90 grados (pi/2 radianes) en sentido antihorario
        rospy.sleep(1)        # Esperar un segundo
        self.move_forward(1.5)  # Mover 4 unidades hacia adelante
        rospy.sleep(1)        # Esperar un segundo
        self.rotate(radians(-90))  # Girar 90 grados (pi/2 radianes) en sentido antihorario
        rospy.sleep(1)        # Esperar un segundo
        self.move_forward(1)  # Mover 4 unidades hacia adelante
        rospy.sleep(1)        # Esperar un segundo
        self.rotate(radians(-90))  # Girar 90 grados (pi/2 radianes) en sentido antihorario
        rospy.sleep(1)        # Esperar un segundo
        self.move_forward(1.5)  # Mover 4 unidades hacia adelante
        rospy.sleep(1)        # Esperar un segundo
        self.rotate(radians(-90))  # Girar 90 grados (pi/2 radianes) en sentido antihorario
        rospy.sleep(1)        # Esperar un segundo
        self.move_forward(1)  # Mover 4 unidades hacia adelante
        rospy.sleep(1)        # Esperar un segundo
        self.rotate(radians(0))  # Girar 90 grados (pi/2 radianes) en sentido antihorario
        rospy.sleep(1)        # Esperar un segundo
        self.move_forward(0)  # Mover 4 unidades hacia adelante
        

if _name_ == '_main_':
    try:
        move_turtle = MoveTurtle()
        move_turtle.move_turtle()
    except rospy.ROSInterruptException:
        pass
