//
//  CTCILinkedLists.cpp
//  DSA
//
//  Created by Shivakiran Ayyagari on 6/6/19.
//  Copyright © 2019 Shivakiran Ayyagari. All rights reserved.
//

#include <stdio.h>
#include <iostream>

#include "CTCILinkedLists.h"

#include <unordered_map>
#include <unordered_set>

class Node
{
public:
    int data;
    Node *next;
};

struct Node *newNode(int data)
{
    Node *temp=new Node;
    temp->data=data;
    temp->next=NULL;
    return temp;
}

//----------------------LinkedLists Implementation--------//
void removeDups(Node *start)
{
    std::unordered_set<int> seen;
    
    Node *curr=start;
    Node *prev=NULL;
    
    while(curr!=NULL)
    {
        if(seen.find(curr->data)!=seen.end())
        {
            prev->next=curr->next;
            delete (curr);
        }
        else
        {
            seen.insert(curr->data);
            prev=curr;
        }
        curr=prev->next;
    }
    
}

void printList(Node *start)
{
    while(start!=NULL)
    {
        std::cout<<start->data<<" ";
        start=start->next;
    }
    std::cout<<"\n";
}


void CTCILinkedLists::removeDuplicates()
{
    
    Node *start = newNode(10);
    start->next = newNode(12);
    start->next->next = newNode(11);
    start->next->next->next = newNode(11);
    start->next->next->next->next = newNode(12);
    start->next->next->next->next->next =newNode(11);
    start->next->next->next->next->next->next =newNode(10);
    
    printList(start);
    removeDups(start);
    printList(start);
    
}
//---------kthToLast------------------//

int CTCILinkedLists::kthToLast(int &num)
{
    Node *start = newNode(10);
    start->next = newNode(12);
    start->next->next = newNode(13);
    start->next->next->next = newNode(14);
    start->next->next->next->next = newNode(15);
    start->next->next->next->next->next =newNode(16);
    start->next->next->next->next->next->next =newNode(17);
    
    Node * countList=start;
    int cnt=0;
    while(countList!=NULL)
    {
        cnt++;
        countList=countList->next;
    }
    int cnt2=0;
    while(start!=NULL)
    {
        if(cnt2==(cnt-1-num))
            return start->data;
        cnt2++;
        start=start->next;
    }
    return 0;
}
//----delete middle element-------//

void CTCILinkedLists::deleteMiddleElement()
{
    Node *start = newNode(10);
    start->next = newNode(12);
    start->next->next = newNode(13);
    start->next->next->next = newNode(14);
    start->next->next->next->next = newNode(15);
    start->next->next->next->next->next =newNode(16);
    start->next->next->next->next->next->next =newNode(17);
    
    printList(start);
    
    Node *slowPtr=start;
    Node *fastPtr=start;
    Node *prev=NULL;
    if(start==NULL)
        return;
    //should return
    
    if(start->next==NULL)
        return;
    while(fastPtr!=NULL && fastPtr->next!=NULL)
    {
        fastPtr=fastPtr->next->next;
        prev=slowPtr;
        slowPtr=slowPtr->next;
    }
    
    prev->next=slowPtr->next;
    delete slowPtr;
    
    printList(start);
}

void CTCILinkedLists::partition(int x)
{
    Node *start = newNode(10);
    start->next = newNode(12);
    start->next->next = newNode(24);
    start->next->next->next = newNode(1);
    start->next->next->next->next = newNode(15);
    start->next->next->next->next->next =newNode(3);
    start->next->next->next->next->next->next =newNode(17);
    
    printList(start);
    
    Node *smallerThanHead=NULL;
    Node *smallerLast=NULL;
    Node *greaterEqualHead=NULL;
    Node *greaterEqualLast=NULL;
    
    while(start!=NULL)
    {
        if(start->data<x)
        {
            if(smallerThanHead==NULL)
            {
                smallerLast=smallerThanHead=start;
            }
            else
            {
                smallerLast->next=start;
                smallerLast=start;
                
            }
        }
        else
        {
            if(greaterEqualHead==NULL)
            {
                greaterEqualLast=greaterEqualHead=start;
            }
            else
            {
                greaterEqualLast->next=start;
                greaterEqualLast=start;
            }
        }
        start=start->next;
    }
    if (greaterEqualLast != NULL)
        greaterEqualLast->next = NULL;
    if(smallerLast==NULL)
    {
        printList(greaterEqualLast);
    }
    else if(greaterEqualLast==NULL)
    {
        printList(smallerLast);
    }
    else
    {
        smallerLast->next=greaterEqualHead;
        printList(smallerThanHead);
    }
    
}

void CTCILinkedLists::addTwoLinkedLists()
{
    Node *firstList=newNode(1);
    firstList->next = newNode(2);
    firstList->next->next = newNode(4);
    firstList->next->next->next = newNode(6);
    
    Node *secondList=newNode(3);
    secondList->next = newNode(2);
    secondList->next->next = newNode(6);
    secondList->next->next->next = newNode(1);
    
    Node *temp=NULL;
    Node *prev=NULL;
    Node *res=NULL;
    int carryOver=0;
    int sum=0;
    while(firstList!=NULL || secondList!=NULL)
    {
        sum=carryOver+(firstList->data+secondList->data);
        carryOver=sum/10;
        
        temp=newNode(sum%10);
        if(res==NULL)
            res=temp;
        else
            prev->next=temp;
        prev=temp;
        
        if(firstList)
            firstList=firstList->next;
        if(secondList)
            secondList=secondList->next;
    }
    
    printList(res);
}


bool CTCILinkedLists::Palindrome()
{
    Node *head=newNode(2);
    head->next = newNode(4);
    head->next->next = newNode(4);
    head->next->next->next = newNode(2);
    
    Node *slow=head, *fast=head, *prev=nullptr, *next=slow;
    while(fast && fast->next) {
        fast=fast->next->next;
        slow = slow->next;
    }
    while(slow) {
        next = slow->next;
        slow->next=prev;
        prev=slow;
        slow=next;
    }
    while(prev && head)
    {
        if(prev->data != head->data) {
            return false;
        }
        prev=prev->next;
        head = head->next;
    }
    
    return true;
}
