#ifndef MYREPLACE_IF_H_INCLUDED
#define MYREPLACE_IF_H_INCLUDED

template<typename T1, typename T2, typename T3>
Myreplace_if(T1 st, T1 ed, T2 pred, const T3& cst){
//    for(; st!=ed; i++){
//        if(pred(*st)) *st=cst;
//    }
    for(T1 i=st; i<ed; i++){
        if(pred(*i)) *i=cst;
    }
}

#endif // MYREPLACE_IF_H_INCLUDED
