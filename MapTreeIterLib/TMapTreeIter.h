#pragma once

#include <queue>
template <class TTK, class TTV> class TNodeTree;
template <class TTK, class TTV> class TMapTree;

template <class TK, class TV>
class TMapTreeIter
{
protected:
	TMapTree<TK, TV>& map;
	std::queue<TNodeTree<TK, TV>*> pos;
public:
	TMapTreeIter(TMapTree<TK, TV>& map);
	bool GoNext();
	TNodeTree<TK, TV>* Get();
	bool IsEnd();
};

template<class TK, class TV>
inline TMapTreeIter<TK, TV>::TMapTreeIter(TMapTree<TK, TV>& _map) : map(_map)
{
	if (_map.root != 0)
		this->pos.push(_map.root);
}

template<class TK, class TV>
inline bool TMapTreeIter<TK, TV>::GoNext()
{
	TNodeTree<TK, TV>* cur = this->pos.front();
	this->pos.pop();
	if (cur->l == 0 && cur->r == 0)
		return false;
	else
	{
		if (cur->l != 0)
			this->pos.push(cur->l);
		if (cur->r != 0)
			this->pos.push(cur->r);
		return true;
	}
}

template<class TK, class TV>
inline TNodeTree<TK, TV>* TMapTreeIter<TK, TV>::Get()
{
	return this->pos.front();
}

template<class TK, class TV>
inline bool TMapTreeIter<TK, TV>::IsEnd()
{
	return this->pos.empty();
}