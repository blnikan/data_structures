# -*- coding: utf-8 -*-
"""
Created on Tue Apr 19 12:33:47 2022

@author: anyutinnd
"""

class NodeTree:
    
     def __init__(self, value = None,l_ch = None,r_ch = None):
         self.value = value
         self.l_ch = l_ch
         self.r_ch = r_ch
     
     
class BTree:
    def __init__(self):
        self.root = None 
    
    def getR(self):
        return self.root
    
    def preadd(self, data, node):
        if data < node.value:
            if node.l_ch != None:
                self.preadd(data ,node.l_ch)
            else:
                node.l_ch = NodeTree(data)
        else:
            if node.r_ch != None:
                self.preadd(data, node.r_ch)            
            else:
                node.r_ch = NodeTree(data)

        
    def newNode(self,data):
        
        if self.root ==None:
            self.root = NodeTree(data)
        else:
            self.preadd(data,self.root)
    

            
    def prePrint(self, node):
        if node != None:
            print("root= ",node.value)
            if node.l_ch == None:
                print("no l_ch")
            else:
                print('l_ch= ',node.l_ch.value)
            
            if node.r_ch == None:
                print('no r_ch')
            else:
                print('r_ch= ',node.r_ch.value)
            
            print()    
            self.prePrint(node.l_ch)
            print()
            self.prePrint(node.r_ch)
                
    def printT(self):
        if self.root!= None:
            self.prePrint(self.root)
    def preF(self, node, data):
        print("f")
        if self.root== data:
            print(self.root.value)
        
    def FindV(self, data):
        print("Find ",data)
        preF(self.root, data)
        
        
     

t =BTree()
while True:
    print("input")
    temp = int(input())
    if temp == 999:
        print('\n'*3)
        break
    t.newNode(temp)

t.printT()





















