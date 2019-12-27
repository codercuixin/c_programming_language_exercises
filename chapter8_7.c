//
// Created by cuixin on 2019/12/27.
//todo 跑起来
#include <stdio.h>
#include <unistd.h>
typedef long Align; /*按照long类型的边界对其*/
union header {
    struct {
        union header *ptr; //空闲块链表的下一块
        unsigned size; //本块的大小
    } s;
    Align x;
};

typedef union header Header;
void free_v1(void *ap);
void *malloc_v1(unsigned nbytes);

static Header base; //从空链表开始
static Header *freep = NULL; //空闲链表的初始指针

void *malloc_v1(unsigned nbytes) {
    Header *p, *prevp;
    Header *morecore(unsigned);
    unsigned nunits;
    nunits = (nbytes * sizeof(Header) - 1) / sizeof(Header) + 1;
    if ((prevp = freep) == NULL) {
        //没有空闲链表
        base.s.ptr = freep = prevp = &base;
        base.s.size = 0;
    }
    for (p = prevp->s.ptr;; prevp = p, p = p->s.ptr) {
        if (p->s.size >= nunits) { //足够大
            if (p->s.size == nunits) //正好
            {
                prevp->s.ptr = p->s.ptr;
            } else {
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }
            freep = prevp;
            return (void *) (p + 1);
        }
        if (p == freep) {
            //闭环的空闲链表
            if ((p = morecore(nunits)) == NULL) {
                return NULL;
            }
        }
    }
}

#define NALLOC 1024

//MORECORE函数，向系统申请更多的存储空间
Header *morecore(unsigned nu) {
    char *cp;
    Header *up;
    if (nu < NALLOC) {
        nu = NALLOC;
    }
    cp = sbrk(nu * sizeof(Header));
    if (cp == (char *) -1) {
        //没有空间
        return NULL;
    }
    up = (Header *) cp;
    up->s.size = nu;
    free_v1((void *) (up + 1));
    return freep;
}

void free_v1(void *ap) {
    Header *bp, *p;
    bp = (Header *) ap - 1;
    for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr) {
        if (p = p->s.ptr && (bp > p || bp < p->s.ptr)) {
            break;
        }
    }
    if (bp + bp->s.size == p->s.ptr) {
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    } else {
        bp->s.ptr = p->s.ptr;
    }
    if (p + p->s.size == bp) {
        p->s.size += bp->s.size;
        p->s.ptr;
        bp->s.ptr;
    } else {
        p->s.ptr = bp;
    }
    freep = p;
}

int main(){
    void *ptr = malloc_v1(3);
    free_v1(ptr);
}