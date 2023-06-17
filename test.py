import streamlit as st

@st.cache
def load_data():
    ...
    return 'data'

st.title('Hello World!')

clicked = False


clicked = st.button('Click me!')

if clicked:
    st.write('Wow!')


