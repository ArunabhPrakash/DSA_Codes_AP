bool isSymmetric(Node* root){
	stack<Node*> s;
	s.push(root);
	s.push(root);
	while(!s.empty()){
		Node* first = s.top();
		s.pop();
		Node* second=s.top();
		s.pop();

		if(first==NULL and second!=NULL){
			return false;
		}
		else if(first!=NULL and second==NULL){
			return false;
		}
		else if(first==NULL and second==NULL){
			continue;
		}
		else{
			if(first->data!=second->data){
				return false;
			}
			else{
				s.push(first->left);
				s.push(second->right);
				s.push(first->right);
				s.push(second->left);
			}
		}
		
	}
	return true;
}
