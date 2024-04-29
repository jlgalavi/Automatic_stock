select * from orders;
select * from pedido;
select * from envio;

INSERT INTO pedido (fecha_pedido, tipos_caja_y_cantidad_de_cada) VALUES ('20/04/2020', '{"S": 5, "M": 3, "L": 2, "XL": 1}');
returning id_pedido into id_pedido 

insert into envio (id_pedido, fecha_envio, fecha_entrega, costo_envio, estado)
values(id_pedido, '08/04/2024', '12/04/2024', 10.2, 'Bueno');

delete from pedido;

alter table pedido
drop column cajas_totales;

select * from total_cajas();

alter table pedido
add column tipos_caja_y_cantidad_de_cada JSONB;

INSERT INTO envio (tipos_caja_y_cantidad_de_cada) 
VALUES ('{"S": 5, "M": 3, "L": 2, "XL": 1}');

alter table pedido
drop column estado;

ALTER TABLE envio DROP CONSTRAINT IF EXISTS fk_pedido_id;
ALTER TABLE pedido
alter column id_pedido type serial;
ALTER TABLE pedido ALTER COLUMN id_pedido SET DEFAULT nextval('pedido_id_pedido_seq');
ALTER TABLE pedido ADD PRIMARY KEY (id_pedido);

ALTER SEQUENCE pedido_id_pedido_seq RESTART WITH 1;

CREATE TABLE envio (
	id_envio serial primary key,
	id_pedido int not null, --clave foránea
	fecha_envio date not null,
	fecha_entrega date not null,
	costo_envio numeric(10, 2),
	estado varchar(50) not null
)

alter table envio
add constraint fk_pedido_id
foreign key (id_pedido)
references pedido(id_pedido);

alter table estados_envios_entregados
add constraint fk_envio_id
foreign key (id_envio)
references envio(id_envio);

drop table orders;

CREATE OR REPLACE FUNCTION total_cajas() RETURNS TABLE (id INT, total INT) AS $$
BEGIN
    RETURN QUERY
    SELECT id, (tipos_caja_y_cantidad_de_cada->>'S')::int + (tipos_caja_y_cantidad_de_cada->>'M')::int + (tipos_caja_y_cantidad_de_cada->>'L')::int + (tipos_caja_y_cantidad_de_cada->>'XL')::int AS total
    FROM pedido;
END; $$
LANGUAGE plpgsql;

