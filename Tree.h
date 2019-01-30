/***************************************************************************
 *   Copyright (C) 2012 by Nicola Di Mauro                                 *
 *   ndm@di.uniba.it                                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef TREE_H
#define TREE_H

template<class I, class N>
	class Tree {
 public:
	typedef I item;
	typedef N node;
	
	virtual void create () = 0;
	virtual bool empty () const = 0;
	virtual void insRoot (node) = 0;
	virtual node root () const = 0;
	virtual node parent (node) const = 0;
	virtual bool leaf (node) const = 0;
	virtual node firstChild (node) const = 0;
	virtual bool lastSibling (node) const = 0;
	virtual node nextSibling (node) const = 0;
	// DA IMPLEMENTARE
	//	virtual void insFirstSubTree (node, Tree &) = 0;
	//	virtual void insSubTree (node, Tree &) = 0;
	virtual void removeSubTree (node) = 0;

	virtual void writeNode (node, item) = 0;
	virtual item readNode (node) const = 0;

	//template<class V> void BFS(node);
	//template<class V> void preorder(node);
	//template<class V> void postorder(node);

};

#endif
